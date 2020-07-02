<?php 
    require_once("default.php");

    function multiexplode ($delimiters,$string) {

        $ready = str_replace($delimiters, $delimiters[0], $string);
        $launch = explode($delimiters[0], $ready);
        return  $launch;
    }

    function getDateFromStr($date) {
        $time = multiexplode(array('-', ' ', ':'), $date);
        $date = array();
        $date['year'] = $time[0];
        $date['month'] = $time[1];
        $date['day'] = $time[2];
        $date['hour'] = $time[3];
        $date['min'] = $time[4];
        
        return $date;
    }

    function getArticles($search = "", $searchTag = "") {
        $html = "";
        $mysqli = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_NAME);
        $mysqli->set_charset('utf8mb4');
        
        if ($mysqli->connect_errno) {

            $html = "Извините, возникла проблема в работе сайта.";
            
        }
         
        if ($search != "" && $searchTag != "") 
            $sql = "SELECT * FROM `articles` WHERE `short_text` LIKE '%{$search}%' OR `title` LIKE '%{$search}%' OR `text` LIKE '%{$search}%' AND `tags` LIKE '%{$searchTag}%' ORDER BY `time` DESC";
        else if ($search == "" && $searchTag != "")        
            $sql = "SELECT * FROM `articles` WHERE `tags` LIKE '%{$searchTag}%' ORDER BY `time` DESC";
        else       
            $sql = "SELECT * FROM `articles` WHERE `short_text` LIKE '%{$search}%' OR `title` LIKE '%{$search}%' OR `text` LIKE '%{$search}%' ORDER BY `time` DESC";
        
        if (!$result = $mysqli->query($sql)) {
            
            $html = "Извините, возникла проблема в работе сайта.";
            
        }
        
        if ($search != "" ) 
            $html .= '<div id="search_title">По Вашему запросу "' . $search . '" найдено статей: ' . $result->num_rows . '</div>';
        
        if ($searchTag != "" && $searchTag != "all" ) 
            $html .= '<div id="search_title">СТАТЕЙ В КАТЕГОРИИ ' . mb_strtoupper($searchTag) . ' (' . $result->num_rows . ')</div>';
        
        $html .= '<div id="article_list">';
        
        while($article = $result->fetch_assoc()) {
        
            $date = getDateFromStr($article['time']);
            $img_title = ($article['img_title'] != '') ? '<div class="img_title_block"><img src="' . $article['img_title'] . '" class="img_title"></div>' : '';
             
            $html .= '<div class="article">
                <div class="article_title">
                    <h1><a href="/article/?article=' . $article['id'] . '">' . mb_strtoupper($article['title']) . '</a></h1>
                    <div class="time_block">
                        <div class="article_time">' .
                            $date['day'] . ' ' . MONTH[$date['month']] . ' ' .$date['year'] . ' В ' . $date['hour'] . ':' . $date['min']
                        . '</div>
                    </div>
                </div>' .
                $img_title
                . '<div class="article_text">' . 
                    $article['short_text'] .'
                </div>
                <div class="article_footer">
                     <div class="article_info">
                        <div class="article_author">
                            <a href="/contact">' .  mb_strtoupper($article['author']) . '
                            </a>
                        </div>
                        <div class="article_comments_info">
                            <a href="/article/?article=' . $article['id'] . '#comments">' . getCountComments($article['id']) . 
                            '</a>
                        </div>
                     </div>
                     <div class="article_tags">
                        <span class="tags_title">КАТЕГОРИИ: </span>'; 
//                                <a href="/article/?article=' . $article['id'] . '">more..</a>
            $tags = json_decode($article['tags']);

            foreach ($tags as $tag) {
                $html .= '
                    <a href="/search/?tag=' . $tag . '">' . mb_strtoupper($tag) . '</a><span>, </span>';
            }   
            $html .= '</div>
                </div>
            </div>';
               
            
        }
        
        $html .= '</div>';
        
        
        $mysqli->close();
        
        echo $html;
    }

    function getArticle($id) {
        $html = "";
        $mysqli = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_NAME);
        $mysqli->set_charset('utf8mb4');
        
        if ($mysqli->connect_errno) {

            $html = "Извините, возникла проблема в работе сайта.";
            
        }
        
        $sql = "SELECT * FROM `articles` WHERE `id` = {$id}";
        
        if (!$result = $mysqli->query($sql)) {
            
            $html = "Извините, возникла проблема в работе сайта.";
            
        }
        
        if ($result->num_rows === 0) {

            $html = "Статья не найдена.";
                
        } 
        
        while($article = $result->fetch_assoc()) {
        
            $date = getDateFromStr($article['time']);
//            $img_title = ($article['img_title'] != '') ? '<img src="' . $article['img_title'] . '" class="photo">' : '';
             
            $html .= '<div class="article_page">
                <div class="article_page_title">
                    <h1>' . mb_strtoupper($article['title']) . '</h1>
                    <div class="time_block">
                        <div class="article_time">' .
                            $date['day'] . ' ' . MONTH[$date['month']] . ' ' .$date['year'] . ' В ' . $date['hour'] . ':' . $date['min']
                        . '</div>
                    </div>
                </div>
               
                <div class="article_page_text">' . 
                     $article['text'] .'
                </div>
                <div class="article_page_footer">
                     <div class="article_info">
                        <div class="article_author">
                            <a href="/contact">' .  mb_strtoupper($article['author']) . '
                            </a>
                        </div>
                        <div class="article_comments_info">
                            <a href="/article/?article=' . $article['id'] . '#comments">' . getCountComments($article['id']) . 
                            '</a>
                        </div>
                     </div>
                     <div class="article_page_tags">
                        <span class="tags_title">КАТЕГОРИИ: </span>'; 
            $tags = json_decode($article['tags']);

            foreach ($tags as $tag) {
                $html .= '<a href="/search/?tag=' . $tag . '">' . mb_strtoupper($tag) . '</a><span>, </span>';
            }   
            $html .= '</div>
                </div>
            </div>';
               
            
        }
        
        
        $mysqli->close();
        
        echo $html;
        
        return $result->num_rows;
    }

    function getArticleTitle($id) {
        $html = "";
        $mysqli = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_NAME);
        $mysqli->set_charset('utf8mb4');
        
        if ($mysqli->connect_errno) {

            $html = "Извините, возникла проблема в работе сайта.";
            
        }
        
        $sql = "SELECT * FROM `articles` WHERE `id` = {$id}";
        
        if (!$result = $mysqli->query($sql)) {
            
            $html = "Извините, возникла проблема в работе сайта.";
            
        }
        
        if ($result->num_rows === 0) {

//            $html = "Статьи не найдены.";
                
        } 
        
        while($article = $result->fetch_assoc()) {
            $html .= mb_strtoupper($article['title']);
        }
        
        
        $mysqli->close();
        
        echo $html;
    }

    function getCountComments($id) {
        $html = "";
        $mysqli = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_NAME);
        $mysqli->set_charset('utf8mb4');
        
        if ($mysqli->connect_errno) {

            $html = "Извините, возникла проблема в работе сайта.";
            
        }
        
        $sql = "SELECT * FROM `comments` WHERE `article` = {$id}";
        
        if (!$result = $mysqli->query($sql)) {
            
            $html = "Извините, возникла проблема в работе сайта.";
            
        }
        
        if ($result->num_rows === 0) {

            $html = 'НЕТ КОММЕНТАРИЕВ';
                
        } else {
            
            $html = $result->num_rows;
            if ($html % 10 == 1 && $html != 11) {
                $html .= ' КОММЕНТАРИЙ';
            } elseif (($html % 10 == 2 || $html % 10 == 3 || $html % 10 == 4) && ($html % 100 != 12 && $html % 100 != 13 && $html % 100 != 14)) {
                $html .= ' КОММЕНТАРИЯ';
            } else {
                $html .= ' КОММЕНТАРИЕВ';
            }
             
        }
        
        $mysqli->close();
        
        return $html;
    }

    function getComments($id, $reply = 0) {
        $html = "";
        $mysqli = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_NAME);
        $mysqli->set_charset('utf8mb4');
        
        if ($mysqli->connect_errno) {

            $html = "Извините, возникла проблема в работе сайта.";
            
        }
        
        $sql = "SELECT * FROM `comments` WHERE `article` = {$id} AND `reply` = {$reply} ORDER BY `time` DESC";
        
        if (!$result = $mysqli->query($sql)) {
            
            $html = "Извините, возникла проблема в работе сайта.";
            
        }
        
        while($comment = $result->fetch_assoc()) {
            $date = getDateFromStr($comment['time']);
            $html .= '<div class="comment_block"><div class="comment">
                           <div class="author_comment">' . $comment['author'] . '</div>
                           <div class="comment_time"> — ' . $date['day'] . ' ' . MONTH[$date['month']] . ' ' .$date['year'] . ' В ' . $date['hour'] . ':' . $date['min'] . '</div>
                           <div class="text_comment">' . $comment['text'] . '</div>
                           

                            <div class="reply_link" data-id="' . $comment['id'] . '" data-name="' . $comment['author'] . '">ОТВЕТИТЬ</div>
                       </div>';
                       
            $html .= getComments($id, $comment['id']);
            $html .= '</div>';    
        }
        
        
        $mysqli->close();
        
        return $html;
    }

    function getTags() {
        $html = "";
        $tags_arr = array();
        $all = 0;
        $mysqli = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_NAME);
        $mysqli->set_charset('utf8mb4');
        
        if ($mysqli->connect_errno) {

            $html = "Извините, возникла проблема в работе сайта.";
            
        }
        
        $sql = "SELECT * FROM `articles`";
        
        if (!$result = $mysqli->query($sql)) {
            
            $html = "Извините, возникла проблема в работе сайта.";
            
        }
        
        while($article = $result->fetch_assoc()) {
        
            $tags = json_decode($article['tags']);

            foreach ($tags as $tag) {
                (isset($tags_arr[mb_strtoupper($tag)])) ? $tags_arr[mb_strtoupper($tag)]++ : $tags_arr[mb_strtoupper($tag)] = 1;
                $all++;
            }
               
            
        }
        
        ksort($tags_arr);
        $min = (!empty($tags_arr)) ? min($tags_arr) : 0;        
        $max = (!empty($tags_arr)) ? max($tags_arr) : 0;
        
        $html .= '<div id="list_tags">';
        foreach ($tags_arr as $tag => $count) {
            $size = 1;
            $opacity = 0.35;
            
            if ($count > $min && $count < $max) {
                $size = 1 + 0.0292 * (($count / $max) * 100);
                $opacity = 0.35 + 0.0065 * (($count / $max) * 100);
            } elseif ($count == $max) {
                $size = 4;
                $opacity = 1;
            }
            
            $html .= '<a class="tag_list_item" href="/search/?tag=' . $tag . '" data-tag="' . $tag . '" data-count="' . $count . '" style="font-size: ' . $size . 'em; opacity:'.$opacity.';">' . $tag .'</a>';
        }
        $html .= '<div id="all_tags_count" data-count="' . $all . '"></div>';
        $html .= '</div>';
        $mysqli->close();
        
        echo $html;
    }

    function getAdmin() {
        $mysqli = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_NAME);
        $mysqli->set_charset('utf8mb4');
        
        if ($mysqli->connect_errno) {

            $html = "Извините, возникла проблема в работе сайта.";
            
        }
        
        $sql = "SELECT * FROM `admin`";
        
        if (!$result = $mysqli->query($sql)) {
            
            $html = "Извините, возникла проблема в работе сайта.";
            
        }
        
        $mysqli->close();
        
        return $result->num_rows;
    }

    function getPass() {

        $chars="qazxswedcvfrtgbnhyujmkiolp1234567890QAZXSWEDCVFRTGBNHYUJMKIOLP";

        $max=10;

        $size=StrLen($chars)-1;


        $password = null;


        while($max--)
            $password .= $chars[rand(0,$size)];


        return $password;
        
    }

    function getAdminInfo() {
        $mysqli = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_NAME);
        $mysqli->set_charset('utf8mb4');
        
        if ($mysqli->connect_errno) {

            $html = "Извините, возникла проблема в работе сайта.";
            
        }
        
        $sql = "SELECT * FROM `admin`";
        
        if (!$result = $mysqli->query($sql)) {
            
            $html = "Извините, возникла проблема в работе сайта.";
            
        }
        
        while($info = $result->fetch_assoc()) {
            $arr = array(
                'login' => $info['login'], 
                'pass' => $info['pass']
            );
        }
        
        $mysqli->close();
        
        return $arr;
    }

    function getNews() {
        $html = "";
        $mysqli = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_NAME);
        $mysqli->set_charset('utf8mb4');
        
        if ($mysqli->connect_errno) {

            $html = "Извините, возникла проблема в работе сайта.";
            
        }
        
        $sql = "SELECT * FROM `articles` ORDER BY `time` DESC LIMIT 4";
        
        if (!$result = $mysqli->query($sql)) {
            
            $html = "Извините, возникла проблема в работе сайта.";
            
        }
        
        $html .= '<div id="news_list">';
        
        while($article = $result->fetch_assoc()) {
        
            $date = getDateFromStr($article['time']);
            $img_title = ($article['img_title'] != '') ? '<div class="img_title_block"><img src="' . $article['img_title'] . '" class="img_title"></div>' : '';
            
            $tags = json_decode($article['tags']);

            foreach ($tags as $tag) {
                $tags_list = '
                    <a href="/search/?tag=' . $tag . '">' . mb_strtoupper($tag) . '</a><span>, </span>';
            }   
            
            $html .= '<div class="title_news">В категории ' . $tag . ' новая запись</div>';
            $html .= '<div class="article">
                <div class="article_title">
                    <h1><a href="/article/?article=' . $article['id'] . '">' . mb_strtoupper($article['title']) . '</a></h1>
                    <div class="time_block">
                        <div class="article_time">' .
                            $date['day'] . ' ' . MONTH[$date['month']] . ' ' .$date['year'] . ' В ' . $date['hour'] . ':' . $date['min']
                        . '</div>
                    </div>
                </div>' .
                $img_title
                . '<div class="article_text">' . 
                    $article['short_text'] .'
                </div>
                <div class="article_footer">
                     <div class="article_info">
                        <div class="article_author">
                            <a href="/contact">' .  mb_strtoupper($article['author']) . '
                            </a>
                        </div>
                        <div class="article_comments_info">
                            <a href="/article/?article=' . $article['id'] . '#comments">' . getCountComments($article['id']) . 
                            '</a>
                        </div>
                     </div>
                     <div class="article_tags">
                        <span class="tags_title">КАТЕГОРИИ: </span>'; 
            $html .= $tags_list;
            $html .= '</div>
                </div>
            </div>';
               
            
        }
        
        $html .= '</div>';
        
        
        $mysqli->close();
        
        echo $html;
    }

?>