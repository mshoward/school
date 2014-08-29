<?php
  //create short variable name
  $DOCUMENT_ROOT = $_SERVER['DOCUMENT_ROOT'];
?>
<html>
<head>
  <title>Bob's Auto Parts - Customer Orders</title>
</head>
<body>
<h1>Bob's Auto Parts</h1>
<h2>Customer Orders</h2>
<?php
//opens the orders.txt file that is stored in the same folder as this file
   @$fp = fopen("orders.txt", 'rb');
//checks and if the file could not be opened, it prints a message
	if(!$fp)
	{
     echo "<p><strong>No orders pending.
           Please try again later.</strong></p>";
     exit;
   }
//loops through and prints out what is in the file until it reaches the end of the file
   while (!feof($fp)) {
      $order= fgets($fp, 999);
      echo $order."<br />";
   }
//gives the position in the file, rewinds the file and gives the new position
   echo "Final position of the file pointer is ".(ftell($fp));
   echo "<br />";
   rewind($fp);
   echo "After rewind, the position is ".(ftell($fp));
   echo "<br />";

   //closes the file
   fclose($fp);

?>
</body>
</html>
