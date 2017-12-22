#!/bin/bash

file=$1

title=$(cat $file | grep "<title>" | sed 's/<title>\(.*\)<\/title>/\1/')
contents=$(cat $file | sed "1, 7 d" | sed '/<\/body>\|<\/html>/ d')

sidebar_contents=$(cat standardese_files.html | sed "1, 7 d" | sed '/<\/body>\|<\/html>/ d')

cat <<EOF > $file
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="utf-8">
<title>$title</title>
<style type="text/css" media="screen">

@import url(https://fonts.googleapis.com/css?family=Roboto:400,400i,700,700i);
@import url(https://fonts.googleapis.com/css?family=Inconsolata:400,700);

@font-face {
    font-family: TOP-1;
    src:url(styles/OTTO-Light.ttf)
    format("truetype")
}

code.standardese-language-cpp {
    margin: 0px;
    display: block;
    background: #FAFAFA;
    padding: 20px;
    overflow: auto;
    border: 1px solid #EEE;
}

code.standardese-language-cpp.standardese-entity-synopsis {
    border-left: 4px solid #e63700;
}

hr.standardese-entity-documentation-break {
    border: none;
}

h1, h2, h3, h4, h5, h6 {
    font-family: TOP-1;
    color: #e63700
}

* {
    font-family: Roboto Regular
}

code * {
    font-family: Inconsolata;
}

code {
    font-family: Inconsolata;
    background: #F5F5F5;
    padding: 0.1em 0.4em;
    border-radius: 0.2em
}

body {
  min-height: 100vh;
}

body, .container {
  display: flex;
  flex-direction: column;
}

.sidebar.left {
  /* put the nav on the left */
  order: -1;
}

.page-contents {
  overflow-x: auto;
}

.page-contents {
    overflow-x: auto;
    max-width: 900px;
    padding: 0px 20px;
}

@media (min-width: 768px) {
  .container {
    flex-direction: row;
    flex: 1;
  }
  .page-contents {
    flex: 1;
  }
  .sidebar {
    /* 12em is the width of the columns */
    flex: 0 0 18em;
  }
}

h3.standardese-entity-documentation-heading {
    font-size: 21px;
}

dt {
    font-family: TOP-1;
    color: #e63700;
}

a {
    color: #e63700;
    text-decoration:  none;
}

ul {
    list-style-type: circle;
}

li#standardese-$(echo "$title" | sed 's/\./\\./g') a {
    color: black;
}

</style>
</head>
<body>
  <div class="container">
    <div class="page-contents">
      $contents
    </div>
    <div class="sidebar left">
      $sidebar_contents
    </div>
  </div>
</body>
</html>

EOF
