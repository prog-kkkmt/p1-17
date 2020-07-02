<?php require_once("../function.php");?>
<!DOCTYPE html> 
<html lang="ru"> 
<head> 
    <meta charset="utf-8"> 
    <link rel="stylesheet" href="/style.css">
    <link rel="shortcut icon" href="/img/favicon.png" type="image/png">
    <title>Новости</title>
</head>
<body> 
    <div class="page">
        <?php require_once('../custom/header.php'); ?>
        <div id="main">
            <div id="content">
                
                <h1 id="title_page">НОВОСТИ</h1>
                <?php getNews(); ?>
            </div>
            <div class="clear"></div>
        </div>
        <?php require_once('../custom/footer.php'); ?>
    </div>
</body> 
</html> 
