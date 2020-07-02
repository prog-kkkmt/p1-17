<?php
    require_once("default.php");
    require_once("function.php");

    session_start();

    if (isset($_POST['pass'])) {
        if (getAdmin()) {
            $info = getAdminInfo();
            if (password_verify ( $_POST['pass'], $info['pass'])) {
                $_SESSION['login'] = $info['login'];
            }
        } else {
            $pass = password_hash($_POST['pass'], PASSWORD_DEFAULT);
            $mysqli = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_NAME);
            $mysqli->set_charset('utf8mb4');

            if ($mysqli->connect_errno) {

                $html = "Извините, возникла проблема в работе сайта.";

            }

            $sql = "INSERT INTO `admin` (`login`, `pass`) VALUES ('admin', '{$pass}')";

            $mysqli->query($sql);


            $mysqli->close();
        }
        
    }

    header('Location: /admin/');

?>