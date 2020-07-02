
<?php require_once("../function.php"); 
      $id = (isset($_GET['article'])) ? $_GET['article'] : "";
      if (empty($_GET)) echo "<script>(window.location.href='/')()</script>"

?>
<!DOCTYPE html> 
<html lang="ru"> 
<head> 
    <meta charset="utf-8"> 
    <link rel="stylesheet" href="/style.css">
    <link rel="shortcut icon" href="/img/favicon.png" type="image/png">
    <title><?php echo getArticleTitle($id); ?></title>
</head>
<body> 
    <div class="page">
        <?php require_once('../custom/header.php'); ?>
        <div id="main">
            
            <div id="content">
                <?php if (getArticle($id)) { ?>
                <a href="#comments"></a>
                <div id="comments_block">
                    <div class="comments_title"><?php echo getCountComments($id); ?></div>
                    <div id="comments">  
                        <?php echo getComments($id); ?>
                    </div>
                    <form method="post" action="/add_comment.php" id="form_comment">
                        <div class="form_title">Оставь свой комментарий</div>
                        <textarea name="text_comment" required></textarea>
                        <div id="reply_to"><span id="cancel_reply">&#10006;</span> Ответ <span id="to"></span></div>
                        <div class="form_foot">
                            <div class="form_foot_inputs">
                                <input name="name_author_comment" placeholder="Ваше имя" required>
                                <input name="email_author_comment" placeholder="Ваш e-mail" required>
                            </div>
                            <button name="submit" type="submit">Опубликовать</button>
                        </div>
                        <input type="hidden" name="reply" id="reply_to_form" value="0">
                        <input type="hidden" name="id_art"  value="<?=$id?>">
                    </form>
                    
                </div>
                <?php } ?>
            </div>
            <div class="clear"></div>
        </div>
        <?php require_once('../custom/footer.php'); ?>
    </div>
    <script>
        var reply = document.getElementsByClassName('reply_link');
        
        for (var i = 0; i < reply.length; i++) {
            reply[i].onclick = function() {
                var id = this.dataset.id;
                var name = this.dataset.name;
                var form = document.getElementById("form_comment");
                
                form.scrollIntoView();
                
                var reply = document.getElementById('reply_to_form');
//                var parent = reply.parentNode;

                reply.value = id;
                
                document.getElementById('reply_to').style.display = 'inline-block';
                document.getElementById('to').innerHTML = name;
                
//                var cloneForm = form.cloneNode(true);
//                parent.append(cloneForm);
                
            }
        }
        
        var cancelReply = document.getElementById('cancel_reply');
        
        cancelReply.onclick = function() {
            document.getElementById('reply_to_form').value = 0;    
            document.getElementById('reply_to').style.display = 'none';
            document.getElementById('to').innerHTML = "";
        }
    </script>
</body> 
</html> 
