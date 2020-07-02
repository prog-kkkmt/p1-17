<?php require_once("../function.php"); session_start();?>
<!DOCTYPE html> 
<html lang="ru"> 
<head> 
    <meta charset="utf-8"> 
    <link rel="stylesheet" href="/style.css">
    <link rel="stylesheet" href="/style-admin.css">
    <link rel="shortcut icon" href="/img/favicon.png" type="image/png">
</head>
<body> 
    <div class="page">
        <?php require_once('../custom/header.php'); ?>
        <div id="main">
            <div id="content">
                <?php if(isset($_SESSION['login'])) { ?>
                <span class="hello">Здравствуй, <b><?=$_SESSION['login']?></b></span>
                <h1 id="title_page">Добавить статью</h1>
                <form id="add_art" method="post" enctype="multipart/form-data" name="article_add" action="/add_article_admin.php">
                    <input name="art_title" placeholder="Название" required>
                    <div id="add_img_title">
                        <label id="add_img_title_form"><input type="file" id="img_title_input" name="img_title">+</label>
                        <span id="output_main"></span>
                    </div>
                    <textarea name="short_text" placeholder="Описание" required></textarea>
                    <div class="paragraph" contenteditable="true"></div>
                    <div class="add_block">
                        <span class="output_add"></span>
                        <label class="add"><input type="file" class="img_input" name="img1">+</label>
                    </div>
                    <div id="add_text">TEXT</div>
                    <input type="hidden" name="text">
                    <input type="text" name="tags" class="input_tags">
                    <button type="submit">ДОБАВИТЬ</button>
                </form>
            </div>
            <div class="clear"></div>
            
            <?php } else { ?>
                <?php if (getAdmin()) { ?>
                <form id="input_form" method="post" action="/input.php">
                    <input type="password" name="pass" placeholder="Пароль" required>
                    <button type="submit">ВОЙТИ</button>
                </form>
                <?php } else { $pass = getPass();?>
                <form id="input_form" method="post" action="/input.php">
                    <span>Предложенный пароль: <b><?=$pass;?></b>. Если вы согласны, то <b>ЗАПОМНИТЕ ЕГО!</b></span>
                    <input type="hidden" name="pass" placeholder="Пароль" value="<?=$pass;?>">
                    <button type="submit">OK</button>
                </form>
                
                <?php } ?>
            <?php } ?>
        </div>
        <?php require_once('../custom/footer.php'); ?>
    </div>
    
    <script>
    function handleFileSelect(evt) {
        var file = evt.target.files[0]; // FileList object
        // Only process image files.
        var reader = new FileReader();
        // Closure to capture the file information.
        reader.onload = (function(theFile) {
            return function(e) {
                // Render thumbnail.
                console.log(escape(theFile.name));
                var span = document.getElementById('output_main');
                span.innerHTML = ['<img class="thumb" src="', e.target.result, '">'].join('');
            };
        })(file);
        // Read in the image file as a data URL.
        reader.readAsDataURL(file);
    }
    document.getElementById('img_title_input').addEventListener('change', handleFileSelect, false);
        
    function handleFileSelectAdd(evt) {
        var file = evt.target.files[0]; // FileList object
        // Only process image files.
        var reader = new FileReader();
        // Closure to capture the file information.
        reader.onload = (function(theFile) {
            return function(e) {
                // Render thumbnail.
                var divs = document.getElementsByClassName('add_block');
                var div = divs[divs.length - 1];
                var div2 = div.cloneNode(true);
                var spans = document.getElementsByClassName('output_add');
                var span = spans[spans.length - 1];
                var adds = document.getElementsByClassName('add');
                var add = adds[adds.length - 1];
                add.style.display = 'none';
                
                if (theFile.type.split('/')[0] == "image") {
                    span.innerHTML = ['<img class="thumb" src="', e.target.result, '">'].join('');

                    var p = document.getElementsByClassName('paragraph');
                    var endp = p[p.length - 1];
                    endp.innerHTML += '%%IMG' + (divs.length) + '%%';
                } else {
                    span.innerHTML = '{' + theFile.name + '} : ' + 'Загрузка завершена.';
                    div.childNodes[3].childNodes[0].setAttribute('name', 'app' + (adds.length));
                    var p = document.getElementsByClassName('paragraph');
                    var endp = p[p.length - 1];
                    endp.innerHTML += '%%APP' + (divs.length) + '%%';
                }
                div2.childNodes[3].childNodes[0].value = '';
                div2.childNodes[3].childNodes[0].setAttribute('name', 'img' + (adds.length + 1));
                
                div.after(div2);
                var block = document.getElementsByClassName('img_input');
                block[block.length - 1].addEventListener('change', handleFileSelectAdd, false);
                
            };
        })(file);
        // Read in the image file as a data URL.
        reader.readAsDataURL(file);
        
    }
        
    document.getElementsByClassName('img_input')[0].addEventListener('change', handleFileSelectAdd, false);
        
    var text = document.getElementById('add_text');
    text.onclick = function() {
        var before = this.previousElementSibling;
        var div = document.createElement('div');
        div.setAttribute('contenteditable', true);
        div.classList.add('paragraph');
        before.before(div);
        div.addEventListener('input', addHide, false);
    }
    
    function addHide() {
        var text = "";
        for (var i = 0; i <= document.getElementsByClassName('paragraph').length - 1; i++){     
            text += document.getElementsByClassName('paragraph')[i].innerHTML; 
        }
        document.forms.article_add.text.value = text;
    }
    
    document.getElementsByClassName('paragraph')[0].addEventListener('input', addHide, false);
</script>
</body> 
</html> 
