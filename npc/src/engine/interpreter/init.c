void sdb_mainloop();

void engine_start() {
  /* Receive commands from user. */
  sdb_mainloop();
}
