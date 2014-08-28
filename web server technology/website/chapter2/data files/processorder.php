<?php
  // create short variable names
  $tireqty = $_POST['tireqty'];
  $oilqty = $_POST['oilqty'];
  $sparkqty = $_POST['sparkqty'];
  $address = $_POST['address'];
  $phone = $_POST['phone'];
  $DOCUMENT_ROOT = $_SERVER['DOCUMENT_ROOT'];
  $date = date('H:i, jS F Y');
?>
<html>
<head>
  <title>Bob's Auto Parts - Order Results</title>
</head>
<body>
<h1>Bob's Auto Parts</h1>
<h2>Order Results</h2>
<?php

	echo "<p>Order processed at ".date('H:i, jS F Y')."</p>";

	echo "<p>Your order is as follows: </p>";
	
// calculates the total number of tires, oils, and sparkplugs
	$totalqty = 0;
	$totalqty = $tireqty + $oilqty + $sparkqty;
	echo "Items ordered: ".$totalqty."<br />";

//prints the appropriate message if the total is 0 or only prints when a given one is not 0
	if ($totalqty == 0) {

	  echo "You did not order anything on the previous page!<br />";

	} else {

	  if ($tireqty > 0) {
		echo $tireqty." tires<br />";
	  }

	  if ($oilqty > 0) {
		echo $oilqty." bottles of oil<br />";
	  }

	  if ($sparkqty > 0) {
		echo $sparkqty." spark plugs<br />";
	  }
	}

//this sestion defines a constant for unit prices for tires, oil and sparkplugs, calculates the total
	$totalamount = 0.00;

	define('TIREPRICE', 100);
	define('OILPRICE', 10);
	define('SPARKPRICE', 4);

	$totalamount = $tireqty * TIREPRICE
				 + $oilqty * OILPRICE
				 + $sparkqty * SPARKPRICE;

	$totalamount=number_format($totalamount, 2, '.', ' ');

	//prints the total, address and quantities
	echo "<p>Total of order is $".$totalamount."</p>";
	echo "<p>Address to ship to is ".$address."</p>";
	echo "<p>Phone Number is ".$phone."</p>";
	$outputstring = $date."\t".$tireqty." tires \t".$oilqty." oil\t"
					.$sparkqty." spark plugs\t\$".$totalamount
					."\t". $address."\n".$phone."\n";



	// open file for appending--orders.txt is in same folder as this file
	@ $fp = fopen("orders.txt", 'ab');

	//flock($fp, LOCK_EX); --need to comment out to work on our server
	//checks and if the file could not be opened, prints a message the order could not be processed
	
	if (!$fp)
	{
		echo "<p><strong> Your order could not be processed at this time.
			Please try again later.</strong></p></body></html>";
		exit;
	}
//writes the output to the file
	fwrite($fp, $outputstring, strlen($outputstring));
	//flock($fp, LOCK_UN);--need to comment out to work on our server
	fclose($fp);

	echo "<p>Order written.</p>";
?>
</body>
</html>
