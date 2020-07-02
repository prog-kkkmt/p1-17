<?php 
    require_once("default.php");
    
    if(!empty($_POST)) {

    //print_r($_POST);
//    print_r($_FILES);
//        echo '<br>';
    $uploaddir = __DIR__ . '/img/upload/';
    $dir = '/img/upload/';
    $img = array();
    $text = $_POST["text"];

    foreach ($_FILES as $key => $value) {
        if (!$value['error']) {
            $uploadfile = $uploaddir . basename($value['name']);
            $img[$key] = $dir . basename($value['name']);
            move_uploaded_file($value['tmp_name'], $uploadfile);
//            echo $key;
            if (strripos($key, 'img') === true) {
                $text = str_replace('%%' . strtoupper($key) . '%%', '<img class="photo" src="' . $dir . basename($value['name']) . '">', $text);
            } else {
                $text = str_replace('%%' . strtoupper($key) . '%%', '<object><embed src="' . $dir . basename($value['name']) . '" width="700" height="500" /></object>', $text);
            }
        }
    }

    $tags = explode(', ', $_POST["tags"]);
    $tags_data = json_encode($tags, JSON_UNESCAPED_UNICODE);

    $arr = array(
        'title' => $_POST["art_title"],
        'img_title' => (isset($img['img_title'])) ? $img['img_title'] : "",
        'short_text' => $_POST["short_text"],
        'text' => $text,    
        'tags' => $tags_data
    );
//    echo '<br>';
//    print_r($arr);
    

    $mysqli = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_NAME);
    $mysqli->set_charset('utf8mb4');

    if ($mysqli->connect_errno) {

        $html = "Извините, возникла проблема в работе сайта.";

    }

    $sql = "INSERT INTO `articles` (`title`, `img_title`, `short_text`, `text`, `tags`) VALUES ('{$arr['title']}', '{$arr['img_title']}', '{$arr['short_text']}', '{$arr['text']}', '{$arr['tags']}')";

    $mysqli->query($sql);


    $mysqli->close();
        
    }

    header('Location: /');
        
    

?>