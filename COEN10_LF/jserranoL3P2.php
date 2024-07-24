<html>

<body> 

<?php

$G1=$_POST["G#1"];
$f=0;
	
	for ($i=0 ; $i<5 ; $i++){
         $Random[$i]= rand(1,20);
	echo $Random[$i];
	echo " "; 
}
 	for ($i=0 ; $i<4 ; $i++){
		if ($G1==$Random[$i]) {
		$f=1;
		break;
} 
}
	if($f==1){
	echo "AMAZING";
	}else{
	echo "WRONG";
}
?>
<form action = "Jserranolab3P1.php" method"POST"/>
<input type ="submit" value ="Back"/>


</body>
</html>


