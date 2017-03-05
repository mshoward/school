using System;
using System.Collections.Generic;
using System.Text;
using System.IO;


namespace Compiler
{
	
	public class Token
	{
		public TokenType tokenType;
		public string lexeme;
		public bool isClassified = false;

		public Token(string s)
		{
			lexeme = string.Copy(s);

		}

		public Token Copy()
		{
			Token ret = new Token(this.lexeme);
			ret.tokenType = this.tokenType;
			return ret;
		}

		public static bool Equals(Token A, Token B)
		{
			if (object.ReferenceEquals(A, B))
				return true;
			if (object.ReferenceEquals(A, null) ||
				object.ReferenceEquals(B, null))
				return false;
			return A.lexeme == B.lexeme;
		}

		public bool Equals(Token B)
		{
			if (object.ReferenceEquals(this, B))
				return true;
			if (object.ReferenceEquals(this, null) ||
				object.ReferenceEquals(B, null))
				return false;
			return this.lexeme == B.lexeme;
		}
		public bool TypeEquals(Token B)
		{
			if (object.ReferenceEquals(this, B))
				return true;
			if (object.ReferenceEquals(this, null) ||
				object.ReferenceEquals(B, null))
				return false;
			return this.tokenType == B.tokenType;
		}


		void setKeywordTypes()
		{
			/*
			if (lexeme.Equals("program"))
				tokenType.Add(TokenType.P1);
			if (lexeme.Equals("begin"))
				tokenType.Add(TokenType.P2);
			if (lexeme.Equals("end."))
				tokenType.Add(TokenType.P3);
			if (lexeme.Equals(":"))
				tokenType.Add(TokenType.D1);
			if (lexeme.Equals("integer"))
				tokenType.Add(TokenType.D2);
			if (lexeme.Equals("array"))
				tokenType.Add(TokenType.AR1);
			if (lexeme.Equals("("))
				tokenType.Add(TokenType.OPENPAREN);
				*/
		}
	}

	

	/// <summary>
	/// The lexical analyzer class
	/// </summary>
	public class LexicalAnalyzer
	{
		public char CurrentChar;
		public char NextChar;
		public StreamReader fs;
		public bool EndOfStreamReached = false;
		public bool Finished
		{
			get
			{
				if (EndOfStreamReached)
				{
					Token testToken = new Token(stringLib.NegativeOne.ToString());
					if(Token.Equals(CurrentToken,testToken))
					{
						return true;
					}
				}
				return false;
			}
		}
		public Token CurrentToken
		{
			get
			{
				if (currentToken == null)
					return new Token("");
				return currentToken;
			}
			set
			{
				currentToken = value;
			}
		}

		public Token NextToken
		{
			get
			{
				if (nextToken == null)
					return new Token("");
				return nextToken;
			}
			set
			{
				nextToken = value;
			}
		}
		Token nextToken;
		Token currentToken;

		/// <summary>
		/// Constructs a Lexical Analyzer with the open stream handed to it.
		/// </summary>
		/// <param name="inputstream"></param>
		public LexicalAnalyzer(StreamReader inputstream)
		{
			fs = inputstream;
			getChar();
			getChar();
			GetNextToken();
			GetNextToken();
		}
		
		/// <summary>
		/// grabs the next token in the stream.  
		/// </summary>
		public void GetNextToken()
		{
			CurrentToken = NextToken;
			//Console.WriteLine("CurrentToken: " + CurrentToken.lexeme);
			string s = "";
			while(stringLib.IsWhiteSpace(CurrentChar))
			{
				getChar();
			}
			if (stringLib.IsNonWhiteSpaceDelim(CurrentChar))
			{
				//check for comments, if it's a comment, just throw it in a token
				if (stringLib.StringStartsComment(CurrentChar.ToString() + NextChar.ToString()))
				{
					s += CurrentChar;
					s += NextChar;
					getChar();
					getChar();
					//just go to the end of the comment.
					while(!stringLib.StringEndsComment(CurrentChar.ToString() + NextChar.ToString()))
					{
						s += CurrentChar;
						getChar();
					}
					//done with comment
					s += CurrentChar;
					s += NextChar;
					getChar();
					getChar();
					NextToken = new Token(s);
					Console.WriteLine("Detected comment : " + s);
					Tokenizer.setType(NextToken);
					Token prevToken = currentToken;
					GetNextToken();
					CurrentToken = prevToken;
					return;
				}//end comment checking

				s += CurrentChar;
				getChar();
			}
			else
			{
				while(!stringLib.isDelim(CurrentChar))
				{
					s += CurrentChar;
					getChar();
				}
			}
			NextToken = new Token(s);
			Tokenizer.setType(NextToken);
		}

		/// <summary>
		/// grabs the next character from the stream, sets end of stream bool if end of stream is reached
		/// </summary>
		/// <returns></returns>
		public bool getChar()
		{
			CurrentChar = NextChar;
			int ret = fs.Read();
			NextChar = char.ToLower((char)ret);
			if (ret == -1)
				EndOfStreamReached = true;
			return EndOfStreamReached;
		}

		

		

	}
}