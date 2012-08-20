<?php

function tropo_ask() {
  $tropo = new Tropo();
  $tropo->say("Hello World!");
  $tropo->renderJson();
}
