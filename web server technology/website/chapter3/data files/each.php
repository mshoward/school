<?
//creates an array with one element and then adds two elements to it later
$prices = array( 'Tires' => 100 );
$prices['Oil'] = 10;
$prices['Spark Plugs'] = 4;
//lists the contents of the prices array, printing out the key and the value of that key
while ($element = each($prices)) {
  echo $element['key'];
  echo " - ";
  echo $element['value'];
  echo "<br />";
}
?>