using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Compiler
{
	

	public class SyntaxAnalyzer
	{
		SemanticAnalyzer semanticAnalyzer;
		public LexicalAnalyzer lex;
		public Stack<SyntaxState> state;
		public List<string> errorLog;
		public SyntaxAnalyzer(StreamReader inputFile)
		{
			semanticAnalyzer = new SemanticAnalyzer();
			lex = new LexicalAnalyzer(inputFile);
			state = new Stack<SyntaxState>();
			errorLog = new List<string>();
		}
		public bool Analyze()
		{
			bool ret = P1();
			if(!ret)
			{
				Console.WriteLine("SYNTAX ERROR");
			}
			return ret;
		}

		/// <summary>
		/// check current token, 
		/// decide which way to go
		/// </summary>
		/// <returns></returns>
		public bool P1()
		{
			bool ret = false;
			if (lex.CurrentToken.TypeEquals(Tokenizer.PROGRAM))
			{
				ret = D0();
				if (ret && lex.NextToken.TypeEquals(Tokenizer.BEGIN))
				{
					lex.GetNextToken();
					ret = S0();
					if (ret && lex.NextToken.TypeEquals(Tokenizer.END))
					{
						lex.GetNextToken();
						ret = true;
						return ret;
					}
					else
					{
						//error state
						log("expected end");
						return false;
					}
				}
				else
				{
					if (lex.NextToken.TypeEquals(Tokenizer.BEGIN))
					{
						log("expected d0 to return false");
					}
					else
					{
						log("expected begin");
					}
					return ret;
				}

			}
			else
			{
				log("expected program");
				return false;
			}
		}

		//two options for D
		public bool D0()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.ID) ||
					lex.NextToken.TypeEquals(Tokenizer.COMMA) ||
					lex.NextToken.TypeEquals(Tokenizer.COLON))
			{
				ret = D1();
			}
			else if (lex.NextToken.TypeEquals(Tokenizer.BEGIN))
			{
				ret = D2();
			}
			else
			{
				log("expected first or follow in d0");
				return false;
			}

			return ret;
		}

		//
		public bool D1()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.ID))
			{
				ret = IL0();
				if (ret)
				{
					if(lex.NextToken.TypeEquals(Tokenizer.COLON))
					{
						lex.GetNextToken();
						ret = D10();
						return ret;
					}
					else
					{
						log("Expected colon in d1");
						return false;
					}
				}
				else
				{
					log("IL0 return false in d1");
				}
			}
			else if (lex.NextToken.TypeEquals(Tokenizer.COMMA))
			{
				ret = IL0();
				if (ret)
				{
					if (lex.NextToken.TypeEquals(Tokenizer.COLON))
					{
						lex.GetNextToken();
						ret = D10();
						return ret;
					}
					else
					{
						log("Expected colon in d1");
						return false;
					}
				}
				else
				{
					log("IL0 return false in d1");
				}
			}
			else if (lex.NextToken.TypeEquals(Tokenizer.COLON))
			{
				//consume, descend
				log("I ate the colon");
				lex.GetNextToken();
				ret = D10();
			}
			return ret;
		}

		public bool D2()
		{
			return true;
		}
		public bool D10()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.ARRAY))
			{
				ret = D11();
			}
			else if (lex.NextToken.TypeEquals(Tokenizer.INTEGER))
			{
				ret = D12();
			}
			else
			{
				log("expected array or integer in d10");
				return false;
			}
			return ret;
		}
		public bool D11()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.ARRAY))
			{
				ret = AR0(); //I know I'm just going to write over it but whatever
				ret = D0();
				return ret;
			}
			log("expected array");
			return false;
		}
		public bool D12()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.INTEGER))
			{
				//consume this one
				while(semanticAnalyzer.DeclarationStack.Count > 0)
				{
					semanticAnalyzer.SymbolTable.Add(semanticAnalyzer.DeclarationStack.Pop(), typeof(int));
				}
				lex.GetNextToken(); //I know I'm just going to write over it but whatever
				ret = D0();
				return ret;
			}
			log("expected integer");
			return false;
		}

		public bool AR0()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.ARRAY))
			{
				lex.GetNextToken();
				ret = AR10();
				return ret;
			}
			log("expected array");
			return false;
		}

		public bool AR10()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.OPENPAREN))
			{
				lex.GetNextToken();
				ret = AR0();
				if (ret && lex.NextToken.TypeEquals(Tokenizer.CLOSEPAREN))
				{
					lex.GetNextToken();
					return true;
				}
				else if(lex.NextToken.TypeEquals(Tokenizer.CLOSEPAREN))
				{
					log("expected close paren");
					return false;
				}
				return ret;
			}
			else
			{
				return true;
			}
		}
		public bool AR11()
		{
			log("expected this function returns false and it's being called when it shouldnt");
			return false;
		}
		public bool AR12()
		{
			log("expected this function returns false and it's being called when it shouldnt");
			return false;
		}
		public bool IL0()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.ID))
			{
				ret = IL1();
				return ret;
			}
			else if (lex.NextToken.TypeEquals(Tokenizer.COMMA))
			{
				ret = IL2();
				return ret;
			}
			else
				return true;
		}

		public bool IL1()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.ID))
			{
				ret = ID0();
				if (ret)
				{
					ret = IL0();
				}
				else
				{
					log("unexpected id0 returned false in il1");
					return false;
				}
				return ret;
			}
			log("expected ID");
			return false;
		}

		public bool IL2()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.COMMA))
			{
				lex.GetNextToken();
				if (lex.NextToken.TypeEquals(Tokenizer.ID))
				{
					ret = ID0();
					if (ret)
					{
						ret = IL0();
					}
					else
					{
						log("unexpected ID0 returned false in IL2");
						return false;
					}
					return ret;
				}
				log("expected id");
				return false;
			}
			log("expected comma");
			return false;
		}

		public bool IL3()
		{
			return true;
		}
		public bool ID0()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.ID))
			{
				lex.GetNextToken();
				if (!semanticAnalyzer.SymbolTable.ContainsKey(lex.CurrentToken))
				{
					semanticAnalyzer.DeclarationStack.Push(lex.CurrentToken.Copy());
				}
				ret = ID10();
				return ret;
			}
			log("expected ID");
			return false;
		}
		public bool ID10()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.OPENPAREN))
			{
				ret = ID11();
				return ret;
			}
			
			return true;
		}
		public bool ID11()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.OPENPAREN))
			{
				lex.GetNextToken();
				ret = SB0();
				if (ret && lex.NextToken.TypeEquals(Tokenizer.CLOSEPAREN))
				{
					lex.GetNextToken();
					return ret;
				}
				else if (!lex.NextToken.TypeEquals(Tokenizer.CLOSEPAREN))
				{
					log("expected close paren");
					return false;
				}
				return ret;
			}
			log("expected openparen");
			return false;
		}
		public bool ID12()
		{
			return true;
		}
		public bool SB0()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.CONS))
			{
				ret = SB1();
				return ret;
			}
			if (lex.NextToken.TypeEquals(Tokenizer.ID))
			{
				ret = SB2();
				return ret;
			}
			if (lex.NextToken.TypeEquals(Tokenizer.COMMA))
			{
				ret = SB3();
				return ret;
			}
			log("expected first in SB");
			return true;
		}
		public bool SB1()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.CONS))
			{
				lex.GetNextToken();
				ret = SB0();
				return ret;
			}
			log("expected cons");
			return false;
		}
		public bool SB2()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.ID))
			{
				lex.GetNextToken();
				ret = SB0();
				return ret;
			}
			log("expected id");
			return false;
		}
		public bool SB3()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.COMMA))
			{
				lex.GetNextToken();
				ret = SB10();
				return ret;
			}
			log("expected comma");
			return false;
		}
		public bool SB4()
		{
			return true;
		}
		public bool SB10()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.CONS))
			{
				ret = SB11();
				return ret;
			}
			else if (lex.NextToken.TypeEquals(Tokenizer.ID))
			{
				ret = SB12();
				return ret;
			}
			log("expected cons or id");
			return false;
		}
		public bool SB11()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.CONS))
			{
				lex.GetNextToken();
				ret = SB0();
				return ret;
			}
			log("expected cons");
			return false;
		}
		public bool SB12()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.ID))
			{
				lex.GetNextToken();
				ret = SB0();
				return ret;
			}
			log("expected id");
			return false;
		}
		public bool S0()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.DO))
			{
				ret = S1();
				return ret;
			}
			if (lex.NextToken.TypeEquals(Tokenizer.OPENPAREN))
			{
				ret = S2();
				return ret;
			}
			if (lex.NextToken.TypeEquals(Tokenizer.ASSIGN))
			{
				ret = S3();
				return ret;
			}
			//log("expected first token in S0");
			return true;
		}
		public bool S1()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.DO))
			{
				lex.GetNextToken();
				ret = S0();
				if (ret)
				{

					ret = S10();
					return ret;
				}
				else
				{
					log("s0 error in s1");
				}
				return ret;
			}
			log("expected do");
			return false;
		}
		public bool S2()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.OPENPAREN))
			{
				lex.GetNextToken();
				ret = IL0();
				if (ret && lex.NextToken.TypeEquals(Tokenizer.CLOSEPAREN))
				{
					lex.GetNextToken();
					ret = S20();
					return ret;
				}
				else
				{
					log("expected close paren");
					return false;
				}
			}
			log("expected open paren");
			return false;
		}

		public bool S3()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.ASSIGN))
			{
				lex.GetNextToken();
				ret = E0();
				if (ret && lex.NextToken.TypeEquals(Tokenizer.TO))
				{
					lex.GetNextToken();
					ret = ID0();
					if (ret && lex.NextToken.TypeEquals(Tokenizer.SEMICOLON))
					{
						lex.GetNextToken();
						ret = S0();
					}
					return ret;
				}
				return ret;
			}
			log("expected assign");
			return false;
		}
		public bool S4()
		{
			return true;
		}

		public bool S10()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.UNLESS))
			{
				lex.GetNextToken();
				ret = C0();
				if (ret && lex.NextToken.TypeEquals(Tokenizer.SEMICOLON))
				{
					lex.GetNextToken();
					ret = S0();
					return ret;
				}
				return ret;
			}
			else if (lex.NextToken.TypeEquals(Tokenizer.WHEN))
			{
				lex.GetNextToken();
				ret = C0();
				if (ret)
				{
					ret = S30();
				}
				return ret;
			}
			log("expected unless or when");
			return false;
		}
		public bool S20()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.IN))
			{
				lex.GetNextToken();
				if (lex.NextToken.TypeEquals(Tokenizer.SEMICOLON))
				{
					lex.GetNextToken();
					ret = S0();
					return ret;
				}
				return ret;
			}
			else if (lex.NextToken.TypeEquals(Tokenizer.OUT))
			{
				lex.GetNextToken();
				if (lex.NextToken.TypeEquals(Tokenizer.SEMICOLON))
				{
					lex.GetNextToken();
					ret = S0();
				}
				return ret;
			}
			log("expected In or Out");
			return false;
		}

		public bool S30()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.SEMICOLON))
			{
				lex.GetNextToken();
				ret = S0();
				return ret;
			}
			else if (lex.NextToken.TypeEquals(Tokenizer.ELSE))
			{
				lex.GetNextToken();
				ret = S0();
				if (ret && lex.NextToken.TypeEquals(Tokenizer.SEMICOLON))
				{
					ret = S0();
				}
				return ret;
			}
			log("expected Semicolon or Else");
			return false;
		}

		public bool E0()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.ID))
			{
				ret = E1();
				return ret;
			}
			else if(lex.NextToken.TypeEquals(Tokenizer.CONS))
			{
				ret = E2();
				return ret;
			}
			else if (lex.NextToken.TypeEquals(Tokenizer.ADD))
			{
				ret = E3();
				return ret;
			}
			else if (lex.NextToken.TypeEquals(Tokenizer.SUBTRACT))
			{
				ret = E4();
				return ret;
			}
			else if (lex.NextToken.TypeEquals(Tokenizer.MULTIPLY))
			{
				ret = E5();
				return ret;
			}
			else if (lex.NextToken.TypeEquals(Tokenizer.DIVIDE))
			{
				ret = E6();
				return ret;
			}
			log("expected a first token in E");
			return false;
		}
		public bool E1()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.ID))
			{
				lex.GetNextToken();
				return true;
			}
			log("expected an id");
			return false;
		}
		public bool E2()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.CONS))
			{
				lex.GetNextToken();
				return true;
			}
			log("expected a constant");
			return false;
		}
		public bool E3()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.ADD))
			{
				lex.GetNextToken();
				ret = E0();
				if (ret)
				{
					ret = E0();
					return ret;
				}
				return ret;
			}
			log("expected add");
			return false;
		}
		public bool E4()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.SUBTRACT))
			{
				lex.GetNextToken();
				ret = E0();
				if (ret)
				{
					ret = E0();
					return ret;
				}
				return ret;
			}
			log("expected subtract");
			return false;
		}
		public bool E5()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.MULTIPLY))
			{
				lex.GetNextToken();
				ret = E0();
				if (ret)
				{
					ret = E0();
					return ret;
				}
				return ret;
			}
			log("expected multiply");
			return false;
		}
		public bool E6()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.DIVIDE))
			{
				lex.GetNextToken();
				ret = E0();
				if (ret)
				{
					ret = E0();
					return ret;
				}
				return ret;
			}
			log("expected divide");
			return false;
		}
		public bool C0()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.LESSTHAN))
			{
				ret = C1();
				return ret;
			}
			else if (lex.NextToken.TypeEquals(Tokenizer.GREATERTHAN))
			{
				ret = C2();
				return ret;
			}
			else if (lex.NextToken.TypeEquals(Tokenizer.EQUALS))
			{
				ret = C3();
				return ret;
			}
			else if (lex.NextToken.TypeEquals(Tokenizer.AND))
			{
				ret = C4();
				return ret;
			}
			else if (lex.NextToken.TypeEquals(Tokenizer.OR))
			{
				ret = C5();
				return ret;
			}
			else if (lex.NextToken.TypeEquals(Tokenizer.NOT))
			{
				ret = C6();
				return ret;
			}
			log("expected a first token in C");
			return false;
		}
		public bool C1()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.LESSTHAN))
			{
				lex.GetNextToken();
				ret = E0();
				if (ret)
				{
					ret = E0();
					return ret;
				}
				return ret;
			}
			log("expected lessthan");
			return false;
		}
		public bool C2()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.GREATERTHAN))
			{
				lex.GetNextToken();
				ret = E0();
				if (ret)
				{
					ret = E0();
					return ret;
				}
				return ret;
			}
			log("expected GREATERTHAN");
			return false;
		}
		public bool C3()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.EQUALS))
			{
				lex.GetNextToken();
				ret = E0();
				if (ret)
				{
					ret = E0();
					return ret;
				}
				return ret;
			}
			log("expected EQUALS");
			return false;
		}
		public bool C4()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.AND))
			{
				lex.GetNextToken();
				ret = C0();
				if (ret)
				{
					ret = C0();
					return ret;
				}
				return ret;
			}
			log("expected AND");
			return false;
		}
		public bool C5()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.OR))
			{
				lex.GetNextToken();
				ret = C0();
				if (ret)
				{
					ret = C0();
					return ret;
				}
				return ret;
			}
			log("expected OR");
			return false;
		}
		public bool C6()
		{
			bool ret = false;
			if (lex.NextToken.TypeEquals(Tokenizer.NOT))
			{
				lex.GetNextToken();
				ret = C0();
				
				return ret;
			}
			log("expected NOT");
			return false;
		}
		public void log(string s)
		{
			errorLog.Add(s);
		}
	}
}
