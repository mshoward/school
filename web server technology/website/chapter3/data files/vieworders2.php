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
  //Read in the entire file.
  //Each order becomes an element in the array
  $orders= file("orders.txt");

  // count the number of orders in the array
  $number_of_orders = count($orders);

  //checks to see there are orders and if not prints a message
  if ($number_of_orders == 0) {
    echo "<p><strong>No orders pending.
          Please try again later.</strong></p>";
  }
// prints a heading for the table
  echo "<table border=\"1\">\n";
  echo "<tr><th bgcolor=\"#DDDDFF\">Order Date</th>
            <th bgcolor=\"#DDDDFF\">Tires</th>
            <th bgcolor=\"#DDDDFF\">Oil</th>
            <th bgcolor=\"#DDDDFF\">Spark Plugs</th>
            <th bgcolor=\"#DDDDFF\">Total</th>
            <th bgcolor=\"#DDDDFF\">Address</th>
         <tr>";
//prints the body of the table
  for ($i=0; $i<$number_of_orders; $i++) {
    //split up each line
    $line = explode("\t", $orders[$i]);

    // keep only the number of items ordered
    $line[1] = intval($line[1]);
    $line[2] = intval($line[2]);
    $line[3] = intval($line[3]);

    // output each order
    echo "<tr>
             <td>".$line[0]."</td>
             <td align=\"right\">".$line[1]."</td>
             <td align=\"right\">".$line[2]."</td>
             <td align=\"right\">".$line[3]."</td>
             <td align=\"right\">".$line[4]."</td>
             <td>".$line[5]."</td>
          </tr>";
  }

  echo "</table>";
?>
</body>
</html>
