<?php require_once("function.php"); ?>

<!DOCTYPE html> 
<html lang="ru"> 
<head> 
    <meta charset="utf-8"> 
    <link rel="stylesheet" href="style.css">
    <link rel="shortcut icon" href="img/favicon.png" type="image/png">
    <title>Гришанова Елена</title>
</head>
<body> 
    <div class="page">
        <?php require_once('custom/header.php'); ?>
        <div id="main">
            <div id="content">
                
                
                <?php getArticles(); ?>
                
            </div>
            <div class="clear"></div>
        </div>
<!--        <object><embed src="/1.pdf" width="700" height="500" /></object>-->
        <?php require_once('custom/footer.php'); ?>
    </div>
</body> 
</html> 
