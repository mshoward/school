<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">

<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>These are not the docs you're looking for...</title>

<link href="../../main.css" rel="stylesheet" type="text/css" media="screen" />

</head>

<body>
	<div class="wrapper">
		<div class = "head">
			<div class = "navigation">
				<span><a href="../../index.html">Home</a></span>
				<span><a href = "../../projects.html">Projects</a></span>
				<span><a href = "../../about.html">About Me / Contact</a></span>
				<span><a href = "http://github.com/mshoward" target="blank">Github</a></span>
			</div>
			<div class = "headings">
				<h2>Specifications (loose)</h2>
				<hr/>
				<div>
					<h3>Database Requests</h3>
					<hr/>
					<p>
						I promise I'm not trying to tell you how to design the database, but having these
							(or something like them) in the database would help me greatly.  Not having
							this information in the database would greatly complicate things.
					</p>
				</div>
			</div>
		</div>
	</div>
	<div class = "headings">
		<table  border=1 >
			
			<tr align="center">
				<td>Table Description</td>
				<td colspan=6 >Attributes...</td>
			</tr>
			
			<tr align="center">
			<td>Lookup_History</td>
				<td>user_GUID</td>
				<td colspan = 5>question_id</td>
			</tr>
			
			<tr align="center">
			<td>Questions</td>
				<td>question_id</td>
				<td>priority</td>
				<td>demographic_id</td>
				<td>required_answers</td>
				<td>current_answers</td>
				<td>question_text</td>
			</tr>
			<tr align="center">
			
			<td>demographics</td>
				<td>demographic_id</td>
				<td>min_age</td>
				<td>max_age</td>
				<td>dorm_list_id</td>
				<td>gender</td>
				<td>etc.</td>
			</tr>
			<tr align="center">
			
			<td>dorm_list</td>
				<td>dorm_list_id</td>
				<td>demographic_id</td>
				<td colspan=4>dorm_id</td>
			</tr>
			
			<tr align="center">
			<td>user</td>
				<td>guid</td>
				<td>min_age</td>
				<td>max_age</td>
				<td>gender</td>
				<td>dorm_id</td>
				<td>major</td>
				
			</tr>
			
			<tr align="center">
			<td>responses</td>
				<td>guid</td>
				<td>question_id</td>
				<td colspan = 4>response_text</td>
			</tr>
			<tr align="center">
			<td colspan=7> I can't think of anything else right now </td>
			</tr>
		
		</table>
	</div>
	<div class="wrapper">
		<div class = "head">
			<div class = "headings">
				<hr/>
				<h3>Other notes:</h3>
				<p>
					Nothing as yet....
				</p>
				<h3>Discussion</h3>
				<hr/>
				<span><a href="forum/forum.html">Forums (under *heavy* construction);</a></span>
				<div class = "comment_section">
					<h4>Comments</h4>
					<p>
						also under construction 
						(need a database for this, it's not set up yet I don't think, will be set up pretty quick, quicker than the forum)
					</p>
				</div>
			</div>
		</div>
	</div>
	<div class = "mid">
	</div>
	<div class = "bot">
		<div class = "headings">
			<form action="comment.php" method="post">
				<table>
					<tr>
						<td>username</td>
						<td><input type="text" name="username">
					</tr>
					<tr>
						<td>Comment:</td>
						<td><textarea rows="4" cols="50" name="comment">Leave your comments here.  You can use &lt;p&gt; and &lt;/p&gt;</textarea></td>
					</tr>
					<tr>
						<td colspan="2" align="center"><input type="submit" value="Submit Comment"/></td>
					</tr>
				</table>
			</form>
			<?php
			$fp = fopen("comments.txt", 'r');
			$str = "";
			$out = "";
			if($fp)
			{
				$out .= "<table border = 1 style=\"width:100%;\">";
				while(!feof($fp))
				{
					$str = fgetss($fp, 1024, "<p></p>");
					//echo "A str was $str<br/>";
					str_replace(array("\r", "\n"), "", $str);
					//if (! (strcmp($str, "(comment)") || strcmp($str, "(comment)\n")))
					if(substr($str, 0, 9) == "(comment)\n" || substr($str, 0, 9) == "(comment)")
					{
						$out .= "<tr>";
						$str = fgetss($fp, 1024, "<p></p>");
						//echo "B str was $str<br/>";
						$out .= "<td>".$str."</td>";
						$out .= "<td>";
						$str = fgetss($fp, 1024, "<p></p>");
						//echo "C str was $str<br/>";
						while(($str != "(/comment)\n" && $str != "(/comment)\r\n" && $str != "(/comment)") && !feof($fp))
						{
							$out .= $str;
							$str = fgetss($fp, 1024, "<p></p>");
							//echo "D str was $str<br/>";
						}
						$out .= "</td></tr>";
					}
					
				}
				$out .= "</table>";
				echo $out;
			}
			?>
		</div>
	</div>
</body>
</html>

