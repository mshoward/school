<?php
  // create short variable names
  
?>
<html>
	<head>
		<title>Maga-Zany's - Order Results</title>
		<link href="../main.css" rel="stylesheet" type="text/css" media="screen" />
	</head>
	<body>
		<div >
			<div class = "head">
				<div class = "headings">
					<h1 style="color: gray;">Maga-Zany's</h1>
					<h2 style="color: gray;">Order List</h2>

					<?php
						$str = "";
						$str2 = "";
						$i = 0;
						$fh = @fopen("orders.txt", 'r');
						if (!$fh)
						{
							echo "Nope!";
						}
						else
						{
							echo "<table border = 1 style = \"float: left; width: 100%;\">";
							while(!feof($fh))
							{
								$i = 0;
								$str = fgetss($fh, 1024);
								//open tags
								echo "<tr>";
								
								while($i < strlen($str))
								{
									if($i + 1 < strlen($str))
										echo "<td>";
									while($str[$i] != '#' && $str[$i] != '\n' && $i < strlen($str))
									{
										echo $str[$i];
										$i++;
									}//next data point
									
									$i++;
									//close td tag
									//echo "closing td";
									if($i < strlen($str))
										echo "</td>";
								}
								echo "</tr>";
							}
							echo "</table>";
						}
						
						
						//checks the $find variable to see how the customer was found and prints appropriate message
					?>
					<a href="magazine_business_index.html">Home </a>
				</div>
			</div>
		</div>
	</body>
</html>