// Author: Ángel
// Code released into the public domain
//
// Modificaciones por
// Felipe Vallejo Molina
// felipevm07@gmail.com
// 2023.6


#include <algorithm>
#include <string>
#include <fstream>
#include <cstdint>
#include <cstddef>
#include <vector>

#pragma once
using namespace std;

namespace textTrad
{
	struct Color
	{
		uint8_t r, g, b;
	};

	class Margins
	{
		float m_left;
		float m_right;
		float m_top;
		float m_bottom;

	public:

		float& left() { return m_left; }
		const float& left() const { return m_left; }

	};



	struct Background
	{
		Color m_color;

	public:

		Color& color() { return m_color; }
		const Color& color() const { return m_color; }
	};

	class Document
	{
		class Format
		{
			Margins    m_margins;
			Background m_background;
		public:

			Margins& margins() { return m_margins; }
			const Margins& margins() const { return m_margins; }

			Background& background() { return m_background; }
			const Background& background() const { return m_background; }
		};

	private:

		wstring m_title;
		wstring m_author;
		Format  m_format;

	public:

		wstring& title() { return m_title; }
		const wstring& title() const { return m_title; }

		wstring& author() { return m_author; }
		const wstring& author() const { return m_author; }

		Format& format() { return m_format; }
		const Format& format() const { return m_format; }
	};

}
