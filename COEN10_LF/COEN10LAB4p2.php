<html> 

<body> 

<?php

$G1=$_POST["N1"];
$G2=$_POST["N2"];
$G3=$_POST["N3"];
$G4=$_POST["N4"];
$G5=$_POST["N5"];

$Guessed= array("$G1","$G2","$G3","$G4","$G5");

echo "You guessed ";
   for ($i=0; $i<5 ; $i++)  // Loop to show user their numbers//
{
	echo $Guessed[$i];
 	echo " ";
}
	echo "<br>";
	echo " Lottery numbers are: ";

	for ($i=0; $i<5 ; $i++)   // Loop to make sure there are no duplicates//
	{
	  $Rand[$i]=Rand(1,20);
	  for ($j = $i-1; $j>=0 ; $j--)
	  {
	    if ($Rand[$i] == $Rand[$j]) 
	    {
		$i--;
		break;	    }
	 }
       }
	for ($i=0; $i<5 ; $i++)	
{
	echo $Rand[$i];
	echo " ";
}
	
$size=count($Guessed);
$size2=count($Rand);
$count=0;    //variable used to keep track of duplictates//

	for ($i=0; $i<$size; $i++){  //compares guessed #'s with lottery #'s//
	 for ($j=0; $j<$size2; $j++){
	   if ($Guessed[$i]==$Rand[$j])
		$count++;
				      
                                    }
				  } 
	echo "<br>";
         echo "you have $count Matches";
				  
?>
<form action = "COENLab4.php" method"POST"/>
<input type ="submit" value ="Back"/> 

</body>
</html>
