<?php 
require_once('conecta.php');

$sql = "SELECT wea_name, wea_temp, wea_humid, wea_date FROM weather ORDER BY id DESC limit 1";
$sqll = "SELECT ar_temp FROM ar ORDER BY ar_id";
$result = $conn->query($sql);
$temp =0;
$humid =0;

if ($result->num_rows > 0) {
    // output data of each row
    while($row = $result->fetch_assoc()) {
	 $temp =$row["wea_temp"];
	 $humid =$row["wea_humid"];
	}
	} else {
    echo "0 results";
}

$result2 = $conn->query($sqll);
$tempe =0;
if ($result2->num_rows > 0) {
    // output data of each row
    while($row = $result2->fetch_assoc()) {
		$tempe =$row["ar_temp"];
		
	}
} else {
    echo "0 results";
}		

$conn->close();


	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
?>