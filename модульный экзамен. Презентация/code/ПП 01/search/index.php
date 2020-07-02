
<?php require_once("../function.php"); 
?>

<!DOCTYPE html> 
<html lang="ru"> 
<head> 
    <meta charset="utf-8"> 
    <link rel="stylesheet" href="/style.css">
    <link rel="shortcut icon" href="/img/favicon.png" type="image/png">
    <title>Поиск...</title>
</head>
<body> 
    <div class="page">
        <?php require_once('../custom/header.php'); ?>
        <div id="main">
            <div id="content">
            <?php if (isset($_GET['tag']) && $_GET['tag'] == "all") { ?>
                 <div id="search_title">КАТЕГОРИИ</div>
            <?php  getTags();} ?>
                
                <?php if (isset($_GET['word'])) getArticles($_GET['word']); ?>
                <?php if (isset($_GET['tag']) && $_GET['tag'] != '') getArticles("", $_GET['tag']); ?>
                <?php if (empty($_GET)) { ?>
                    <div id="search_title">ПОИСК...</div>
                    <form name="search" id="form_search" class="header_item" action="/search" method="get">
                        <input type="text" name="word" class="form_item" value="<?php echo (isset($_GET['word'])) ? $_GET['word'] : ""; ?>" placeholder="Введите запрос" required>
                        <button type="submit" class="form_item">ПОИСК</button>
                    </form>
                <?php } ?>
            </div>
            <div class="clear"></div>
        </div>
        <?php require_once('../custom/footer.php'); ?>
    </div>
    
    <script>
        var tags = document.getElementsByClassName('tag_list_item');
        
        for (var i = 0; i < tags.length; i++) {
            
        }
    </script>
</body> 
</html> 
