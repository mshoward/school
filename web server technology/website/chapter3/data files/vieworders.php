<?php
//create short variable name
$DOCUMENT_ROOT = $_SERVER['DOCUMENT_ROOT'];

//opens orders.txt file and counts the number of orders stored in the array --each order becomes an element in the order array
$orders= file("orders.txt");
$number_of_orders = count($orders);

//if not orders it displays a message
if ($number_of_orders == 0) {
  echo "<p><strong>No orders pending.
       Please try again later.</strong></p>";
}
//loop to print the number of orders
for ($i=0; $i<$number_of_orders; $i++) {
  echo $orders[$i]."<br />";
}
?>
