<html>
<body>
<table border="0" cellpadding="3">
<tr>
  <td bgcolor="#CCCCCC" align="center">Distance</td>
  <td bgcolor="#CCCCCC" align="center">Cost</td>
</tr>
<?

$distance = 0; //initialize distance to 0
 
//while loop to print the freight table (distance and cost(distance/10)
//done in multiples of 50 miles
while ($distance <= 250) 
{
	echo "<tr>
		<td align=\"right\">".$distance."</td>
		<td align=\"right\">".($distance / 5)."</td>
		</tr>\n";

	$distance += 50;
}

?>
</table>
</body>
</html>

