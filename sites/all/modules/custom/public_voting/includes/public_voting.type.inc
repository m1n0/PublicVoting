<?php

function tropo_ask() {
  $tropo = new Tropo();

  $options = array(
    "attempts" => 3,
    "bargein" => true,
    "choices" => "[5 DIGITS]",
    "name" => "zip",
    "timeout" => 5
  );

  $tropo->ask("Please enter your 5 digit zip code.", $options);

  $tropo->on(array("event" => "continue", "next" => url('tropo/result.json'), "say" => "Please hold."));
  $tropo->on(array("event" => "error", "next" => "get_zip_code.php?uri=error", "say" => "An error has occured."));


  $tropo->renderJson();
}


//dispatch_post('/end', 'zip_end');
function tropo_result() {
  $tropo = new Tropo();

  $result = new Result();
	$id = $result->getValue();

  $tropo->say($id);


  $tropo->renderJson();
}