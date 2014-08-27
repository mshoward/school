<?php
  // create short variable names
  $numCar = $_POST['numCars'];
  $numBus = $_POST['numBus'];
  $numHip = $_POST['numHip'];
  $numComp = $_POST['numComp'];
?>
<html>
<head>
  <title>Maga-Zany's - Order Results</title>
<link href="../main.css" rel="stylesheet" type="text/css" media="screen" />
</head>
<body>
<div class = "wrapper">
<div class = "head">
<div class = "headings">
<h1>Maga-Zany's</h1>
<h2>Order Results</h2>

<?php

	echo "<p>Order processed at ".date('H:i, jS F Y')."</p>";

	echo "<p>Your order is as follows: </p>";
    // get total quantity 
	$numtotal = 0;  //set initial value to 0
	$numtotal = $numCar + $numBus + $numHip + $numComp;  //add the three variables
	$temp = 0;
	$shipping = 0.75;//this gets lost, I'll add it at the end
	echo "Items ordered: ".$numtotal."<br /><hr />";

//Prints appropiate message if $totalqty is 0 and only prints others if it is something other than 0
	if ($numtotal == 0) 
	{
		
		echo "You did not order anything on the previous page!<br />";
		
	}
	else
	{
	
		if ($numCar > 0)
		{
			$temp += $numCar;
			$shipping = ((int)($temp / 10)) * 0.50;
			echo $numCar." copies of Cars Maxed.<br />
			This brings your current number of copies up to ".$temp."<br />
			Running Shipping: ".$shipping."<br /><br />";
		}
		if ($numBus > 0)
		{
			$temp += $numBus;
			$shipping = ((int)($temp / 10)) * 0.50;
			echo $numBus." copies of Business Mag for Business People.<br />
			This brings your current number of copies up to ".$temp."<br />
			Running Shipping: ".$shipping."<br /><br />";
		}
		if ($numHip > 0)
		{
			$temp += $numHip;
			$shipping = ((int)($temp / 10)) * 0.50;
			echo $numBus." copies of New and Unheard of Trends for Hipsters!<br />
			This brings your current number of copies up to ".$temp."<br />
			Running Shipping: ".$shipping."<br /><br />";
		}
		if ($numComp > 0)
		{
			$temp += $numComp;
			$shipping = ((int)($temp / 10)) * 0.50;
			echo $numComp." copies of Computer Science for Sentient AI.<br />
			This brings your current number of copies up to ".$temp."<br />
			Running Shipping: ".$shipping."<br /><br /><br />";
		}
		
	}
	
	
	$totalamount = 0.00;  //initialize $totalamount to 0
	
	//defines constant values for prices for tires, oil, and spark plugs
	define('CAR_PRICE', 3.00);   
	define('BUS_PRICE', 15.00);
	define('HIP_PRICE', 3.14);
	define('COMP_PRICE', 5.00);
	
	//calculates the totalamount by multiply each quantity by its unit price and adding them
	$totalamount += CAR_PRICE * $numCar;
	$totalamount += BUS_PRICE * $numBus;
	$totalamount += HIP_PRICE * $numHip;
	$totalamount += COMP_PRICE * $numComp;
				
	echo "Subtotal: $".number_format($totalamount,2)."<br />";

	//sets taxrate and calculat the $totalamount
	//$taxrate = 0.10;  // local sales tax is 10%
	$shipping += 0.75;
	$totalamount += $shipping;
	echo "Total including shipping: $".number_format($totalamount,2)."<br />";

	//checks the $find variable to see how the customer was found and prints appropriate message


?>
</div>
</div>
</div>
</body>
</html>