// Author: Ángel
// Code released into the public domain
//
// Modificaciones por
// Felipe Vallejo Molina
// felipevm07@gmail.com
// 2022.6

#pragma once

#include <algorithm>
#include <string>
#include <fstream>
#include <cstdint>
#include <cstddef>
#include <vector>
#include <Document.hpp>

using namespace std;

namespace textTrad 
{	

	class Stream
	{
	public:

		virtual ~Stream() = default;

		virtual bool good() const = 0;
		virtual bool bad() const = 0;
		virtual bool fail() const = 0;
	};

	class Input_Stream : public Stream
	{
	public:
		
		virtual byte   read() = 0;
		virtual size_t read(const byte* buffer, size_t amount) = 0;
	};

	class Output_Stream : public Stream
	{
	public:

		virtual void write(byte value) = 0;
		virtual void write(const byte* buffer, size_t amount) = 0;
	};

	class OFStream : public Output_Stream
	{
		std::ofstream stream;

	public:

		OFStream(const string& path) : stream(path, ofstream::trunc | ofstream::binary)
		{
		}

		bool good() const { return stream.good(); }
		bool bad() const { return stream.bad(); }
		bool fail() const { return stream.fail(); }

		void write(byte value)
		{
			stream.put(char(value));
		}

		void write(const byte* buffer, size_t amount)
		{
			stream.write(reinterpret_cast<const char*>(buffer), amount);
		}
	};

	class Binary_Serializer
	{

		Output_Stream* stream;

	public:

		Binary_Serializer(Output_Stream& given_stream) : stream(&given_stream)
		{
		}

		void serialize_int8(const int8_t& value)
		{
			stream->write(reinterpret_cast<const byte&>(value));
		}

		void serialize_int16(const int16_t& value)
		{
			stream->write(byte(value >> 8));
			stream->write(byte(value));
		}

		void serialize_int32(const int32_t& value)
		{
			stream->write(byte(value >> 24));
			stream->write(byte(value >> 16));
			stream->write(byte(value >> 8));
			stream->write(byte(value));
		}

		void serialize_int64(const int64_t& value);

		// versiones de enteros sin signo...

		void serialize_float32(const float& value)
		{
			auto uint_value_32 = reinterpret_cast<const uint32_t&>(value);
			stream->write(byte(uint_value_32 >> 24));
			stream->write(byte(uint_value_32 >> 16));
			stream->write(byte(uint_value_32 >> 8));
			stream->write(byte(uint_value_32));
		}

		void serialize_float64(const double& value);

		void serialize_bool(bool value)
		{
			//stream->write (byte(value ? 1 : 0));
			stream->write(byte(value));
		}

		void serialize_string(const wstring& value)
		{
			auto bytes = string_to_utf8(value);

			serialize_int32(bytes.size());

			stream->write(bytes.data(), bytes.size());
		}


	private:

		vector<byte> string_to_utf8(const wstring& value)
		{
			vector<byte> result(value.size());
			// NOTA: esta no es una conversión UTF8 correcta:
			for (size_t i = 0; i < value.size(); ++i) result[i] = byte(value[i]);
			return result;
		}

	};

	class Bdoc_Serializer
	{
		class Document;

		const Document* document;

	public:

		Bdoc_Serializer(const Document& given_document) : document(&given_document)
		{
		}

		void serialize(const string& path)
		{
			OFStream stream(path);

			if (not stream.good()) throw "Error: can't create the stream";

			Binary_Serializer writer(stream);

			writer.serialize_string(L"bdoc!");		// MARK
			writer.serialize_int8(0);			// VERSIÓN DEL FORMATO

			serialize_document(writer, *document);
		}

	private:

		void serialize_document(Binary_Serializer& writer, const Document& document) {}

	};
}