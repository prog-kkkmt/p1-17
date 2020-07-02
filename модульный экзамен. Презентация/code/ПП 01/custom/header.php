<div id="header">
    <a href="/" class="title_link"><div id="label" class="header_item">
        <div id="img_label"><img src="/img/customLogo.jpg"></div>
            <div id="text_label"><div id="main_head_text">Гришанова Елена</div><div id="head_text">Преподаватель математики</div><div id="sub_main_head_text">Для коллег, студентов и их родителей</div></div>
    </div></a>
    <div id="search" class="header_item">
        <form name="search" id="form_search" class="header_item" action="/search" method="get">
            <input type="text" name="word" class="form_item" value="<?php echo (isset($_GET['word'])) ? $_GET['word'] : ""; ?>" placeholder="Введите запрос" required>
            <button type="submit" class="form_item">ПОИСК</button>
        </form>
    </div>
    <div id="map_top" class="header_item">
            <ul id="map_list" class="header_item">
                <li class="map_item"><a href="/">ГЛАВНАЯ</a></li>
                <li class="map_item"><a href="/search/?tag=all">КАТЕГОРИИ</a></li>
                <li class="map_item"><a href="/news">НОВОСТИ</a></li>
                <li class="map_item"><a href="/contact">О НАС</a></li>
<!--
                <li class="map_item"><a href="#">LINK</a></li>
                <li class="map_item"><a href="#">LINK</a></li>
-->
            </ul>
    </div>
</div>