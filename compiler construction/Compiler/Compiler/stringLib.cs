using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Compiler
{
	public static class stringLib
	{
		public static char NegativeOne
		{
			get { return (char)negativeOne; }
		}
		static int negativeOne = -1;
		public static string copy(string s)
		{
			return string.Copy(s);
		}

		/// <summary>
		/// tells whether or not a character is a delimiting character, 
		/// i.e. the beginning of another token, or the end of one.
		/// </summary>
		/// <param name="c"></param>
		/// <returns></returns>
		public static bool isDelim(char c)
		{
			return char.IsWhiteSpace(c) | IsNonWhiteSpaceDelim(c);
		}

		/// <summary>
		/// returns whether or not a character is a non-whitespace delimiter
		/// </summary>
		/// <param name="c"></param>
		/// <returns></returns>
		public static bool IsNonWhiteSpaceDelim(char c)
		{
			return (c == ';') |
				(c == '(') |
				(c == ')') |
				(c == ',') |
				(c == ':') |
				(c == '+') |
				(c == '-') |
				(c == '*') |
				(c == '/') |
				(c == '=') |
				(c == '<') |
				(c == NegativeOne) |
				(c == '>');
		}

		/// <summary>
		/// returns whether or not a character is whitespace
		/// </summary>
		/// <param name="c"></param>
		/// <returns></returns>
		public static bool IsWhiteSpace(char c)
		{
			return char.IsWhiteSpace(c);
		}

		/// <summary>
		/// Returns whether the string is of the form "/*".
		/// </summary>
		/// <param name="FirstCharConcatSecondChar">(first_char.ToString() + second_char.ToString())</param>
		/// <returns></returns>
		public static bool StringStartsComment(string FirstCharConcatSecondChar)
		{
			return FirstCharConcatSecondChar == "/*";
		}

		/// <summary>
		/// Returns whether the string is of the form "*/"
		/// </summary>
		/// <param name="FirstCharConcatSecondChar">(first_char.ToString() + second_char.ToString())</param>
		/// <returns></returns>
		public static bool StringEndsComment(string FirstCharConcatSecondChar)
		{
			return FirstCharConcatSecondChar == "*/";
		}

	}

	class RegExes
	{
		public List<string> patterns;

		public RegExes(string pat)
		{
			
		}

		public bool isMatch(string s)
		{
			


			return false;
		}

	}
}
