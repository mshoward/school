<?php
//array to story the pictures
  $pictures = array('tire.jpg', 'oil.jpg', 'spark_plug.jpg',
                    'door.jpg', 'steering_wheel.jpg',
                    'thermostat.jpg', 'wiper_blade.jpg',
                    'gasket.jpg', 'brake_pad.jpg','wheel.jpg');

  shuffle($pictures);  //randomly selects pictures to display from the array
?>
<html>
<head>
  <title>Bob's Auto Parts</title>
</head>
<body>

<h1>Bob's Auto Parts</h1>
<div align="center">
<table width = 100%>

<?php
	//for loop to display 4 pictures that were randomly selected from the array
	for ($i = 0; $i < 4; $i++)
	{
		if($i % 2 == 0)
			echo "<tr>";
		echo "<td align=\"center\"><img src=\"";
		echo $pictures[$i];
		echo "\"/></td>";
		if($i % 2 != 0)
			echo "</tr>";
	}
?>
</table>
</div>
</body>
</html>
