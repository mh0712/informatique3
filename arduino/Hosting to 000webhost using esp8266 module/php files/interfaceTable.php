<?php
//all of this code used for refreshing the page
$page = $_SERVER['PHP_SELF'];
$sec = "15";
?>
<html>
    <head>
    <meta http-equiv="refresh" content="<?php echo $sec?>;URL='<?php echo $page?>'">
    </head>
    <body>
    
<?php

$con=mysqli_connect('localhost','id18787726_seaker','93)uFs%G$JKZ]#BY','id18787726_esp8266');// SREVER , USER NAME , PASS , DATABASE NAME

// Check connection
if (mysqli_connect_errno()) {
    echo "Failed to connect to MySQL: " . mysqli_connect_error();
  }

//pull out the table
$result = mysqli_query($con,"SELECT * FROM DBTABLE");//table select

//print some nice text at the top
echo "<div style ='font:24px/21px fantasy,tahoma,sans-serif;color:#000000'> ESP8266 seaker <br> </div>";

//draw the table
echo "<table border='3'>
<tr>
<th>id</th>
<th>d1</th>
</tr>";
//loop through the table and print the data into the table
while($row = mysqli_fetch_array($result)) {

  echo "<tr>";
  $unit_id = $row['id'];
  echo "<td>" . $row['id'] . "</td>";

echo "<td>" . $row['d1'] . "</td>";
echo "</tr>";
}//while

echo "</table>";

    ?>