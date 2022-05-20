<?php

//loop thru the url and get the variables off it

foreach($_REQUEST as $key => $value){
    if ( $key == "unit"){
        $unit= $value;    
    }
    if ( $key == "d1"){
        $d1= $value; 
    } 
}

// create connecton to sql database

$con=mysqli_connect('localhost','id18787726_seaker','93)uFs%G$JKZ]#BY','id18787726_esp8266');// SREVER , USER NAME , PASS , DATABASE NAME

// Check connection
if (mysqli_connect_errno()) {
    echo "Failed to connect to MySQL: " . mysqli_connect_error();
  }


//update sensor value in database
mysqli_query($con,"UPDATE DBTABLE SET d1 = $d1
WHERE id=$unit");

//pull out the table
$result = mysqli_query($con,"SELECT * FROM DBTABLE");//table select

//loop through the table and filter out data for this unit id
while($row = mysqli_fetch_array($result)) {
    if($row['id'] == $unit){
    $d1 = $row['d1'];
    echo "_d1$d1##";
    }
    
}//while

?>