<?php

function tropo_ask() {
  $tropo = new Tropo();
  $tropo->say("Hello World!");

  $options = array("attempts" => 3, "bargein" => true, "choices" => "[5 DIGITS]", "name" => "zip", "timeout" => 5);

  $tropo->ask("Please enter your 5 digit zip code.", $options);

  $tropo->on(array("event" => "continue", "next" => url('tropo/result.json'), "say" => "Please hold."));
  $tropo->on(array("event" => "error", "next" => "get_zip_code.php?uri=error", "say" => "An error has occured."));


  $tropo->renderJson();
}


function tropo_result() {
  $tropo = new Tropo();
  $tropo->say("you sucker");
  $tropo->renderJson();
}