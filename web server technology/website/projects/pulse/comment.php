
<html>
	<head>
		
	</head>
	<body>
<?php
	// create short variable names
	$comment = $_POST['comment'];
	$username = $_POST['username'];
	$fp = fopen("comments.txt", 'a');
	if($fp)
	{
		$output = "(comment)\n".$username."\n";
		$output .= $comment;
		$output .= "\n(/comment)\n";
		fwrite($fp, $output);
		fclose($fp);
		echo "<a href=\"specifications.php\">Thank you</a>";
	}
?>
		
	</body>
</html>