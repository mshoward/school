<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">

<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>These are not the docs you're looking for...</title>

<link href="../main.css" rel="stylesheet" type="text/css" media="screen" />

</head>

<body>

	<div class="wrapper">
		<div class = "head">
			<div class = "navigation">
				<span><a href="../index.html">Home</a></span>
				<span><a href = "../projects.html">Projects</a></span>
				<span><a href = "../about.html">About Me / Contact</a></span>
				<span><a href = "../http://github.com/mshoward" target="blank">Github</a></span>
				
			</div>
			<div class = "headings">
				<h2>Maga-zany's</h2>
				<hr/>
				<a href="magazine_business_form.html">Our BUYING form!</a>
				
			</div>
		</div><!-- closing head div -->
		
		<div class = "mid">
			
			<div class = "homeContent">
				<p>
					I sell magazines.
				</p>
			</div>
			
			<h3><a class = "headings" href="magazine_business_form.html">BUY</a> from me!</h3> <hr/>
			<div class = "homeUpdates">
				
			</div>
		</div><!-- closing mid div -->
		
		<div class = "headings">
			<a href = "magazine_view_orders.php">Employees only(Order List)</a><br/>
			<?php
			$output = "";
			$pics = array('people.jpg', 'time.jpg', 'sport.jpg', 'jobs.jpg');
			shuffle($pics);
			for($i = 0; $i < 3; $i++)
			{
				$output .= "<img width=\"75\" height=\"75\" src=\"$pics[$i]\" style=\"padding: 25px;\">";
			}
			echo $output;
			?>
		</div><!-- closing bot div -->
	</div> <!-- closing wrapper div -->

</body>
</html>
