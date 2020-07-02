<?php 
    require_once(__DIR__ . "/default.php");


    $text = htmlspecialchars($_POST['text_comment']);
    $author = $_POST['name_author_comment'];
    $reply = $_POST['reply'];
    $email = $_POST['email_author_comment'];
    $id_art = $_POST['id_art'];

    $mysqli = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_NAME);
    $mysqli->set_charset('utf8mb4');

    if ($mysqli->connect_errno) {

        $html = "Извините, возникла проблема в работе сайта.";

    }

    $sql = "INSERT INTO `comments` (`author`, `text`, `article`, `reply`, `email`) VALUES ('{$author}', '{$text}', '{$id_art}', '{$reply}', '{$email}')";

    $mysqli->query($sql);


    $mysqli->close();
    
    header("Location: http://www.grishanova.online/article/?article={$id_art}#comments");
?>