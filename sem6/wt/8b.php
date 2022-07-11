<?php
$a = array(array(1, 2, 3), array(4, 5, 6), array(7, 8, 9));
$b = array(array(7, 8, 9), array(4, 5, 6), array(1, 2, 3));
$m = count($a);
$n = count($a[2]);
$p = count($b);
$q = count($b[2]);

function printa($array, $alen, $subalen)
{
	for ($row = 0; $row < $alen; $row++) {
		for ($col = 0; $col < $subalen; $col++) echo " " . $array[$row][$col];
		echo "<br/>";
	}
}

echo "the first matrix :" . "<br/>";
printa($a, $m, $n);
echo "the second matrix :" . "<br/>";
printa($b, $p, $q);

echo "the transpose for the first matrix is:" . "<br/>";
for ($row = 0; $row < $m; $row++) {
	for ($col = 0; $col < $n; $col++) echo " " . $a[$col][$row];
	echo "<br/>";
}

if (($m === $p) and ($n === $q)) {
	echo "the addition of matrices is:" . "<br/>";
	for ($row = 0; $row < 3; $row++) {
		for ($col = 0; $col < 3; $col++)
			echo " " . $a[$row][$col] + $b[$row][$col] . " ";
		echo "<br/>";
	}
}

if ($n === $p) {
	echo " The multiplication of matrices: <br/>";
	$result = array();
	for ($i = 0; $i < $m; $i++) {
		for ($j = 0; $j < $q; $j++) {
			$result[$i][$j] = 0;
			for ($k = 0; $k < $n; $k++)
				$result[$i][$j] += $a[$i][$k] * $b[$k][$j];
		}
	}
	printa($result, $m, $q);
}
