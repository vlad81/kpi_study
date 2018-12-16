<?php
  	$file = fopen("files.xml", 'r+');
	fseek($file, -8, SEEK_END);
	$line = '<file name='."'".$_POST["fileName"]."'".'><content>'.$_POST["content"].'</content></file></files>';
	fwrite($file, $line);
	fclose($file);
?>
