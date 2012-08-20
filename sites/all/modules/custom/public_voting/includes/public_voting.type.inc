<?php

function tropo_ask() {
  $tropo = new Tropo();

  $node = node_load(2);

  $choices = array();
  foreach ($node->choice as $key => $value) {
    $choices[] = $value['chtext'] . '(' . $value['chid'] . ', ' . $value['chtext'] . ')';
  }

  $options = array(
    "attempts" => 3,
    "bargein" => true,
    "choices" => implode(',', $choices),
    "name" => "id",
    "timeout" => 5
  );

  $tropo->say($node->title);

  foreach ($node->choice as $key => $value) {
    $tropo->say("For " . $value['chtext'] . ' press ' . $value['chid']);
  }

  $tropo->ask('', $options);

  $tropo->on(array("event" => "continue", "next" => url('tropo/result.json'), "say" => "Please hold."));
  $tropo->on(array("event" => "error", "next" => "get_zip_code.php?uri=error", "say" => "An error has occured."));


  $tropo->renderJson();
}


function tropo_result() {
  $tropo = new Tropo();

  $result = new Result();
	$id = $result->getValue();

  $tropo->say($id);


  $tropo->renderJson();
}

function tropo_error() {
  $tropo = new Tropo();

  $result = new Result();
	$id = $result->getValue();

  $tropo->say($id . " is an invalid option!");


  $tropo->renderJson();
}