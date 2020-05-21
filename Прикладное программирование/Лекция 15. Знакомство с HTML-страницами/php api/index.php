<?php
$app_id = '9750045206ce405b918a026c2056784e';
$oxr_url = "https://openexchangerates.org/api/latest.json?app_id=" . $app_id;

$ch = curl_init($oxr_url);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);

$json = curl_exec($ch);
curl_close($ch);

$oxr_latest = json_decode($json);
?>

<!DOCTYPE html>
<html>
<head>
	<title>Таблица курса вылют</title>
	<link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
	<div id="date"><?= date('H:i jS F, Y', $oxr_latest->timestamp); ?></div>
	<div id="table">
		<table id="table_currency" border="1" cellspacing="0">
			<caption id="table_caption">Таблица курса валют к <?= $oxr_latest->base; ?></caption>
			<tr id="table_row_caption">
				<td>ID</td>
				<td>Название</td>
				<td>Курс валюты</td>
			</tr>
			
				<?php
					$i = 1;
					foreach ($oxr_latest->rates as $cur => $rate) {
						echo '<tr>';
						echo '<td>' . $i .'</td>';
						echo '<td>' . $cur . '</td>';
						echo '<td>' . $rate . '$</td>';
						echo '</tr>';
						$i = $i + 1;
					} 
				?>
			
		</table>
	</div>
</body>
</html>