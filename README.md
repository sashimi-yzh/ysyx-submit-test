# How to Clone

```
git clone --recurse-submodules git@github.com:WuShFeng/ysyx.git
# Or, If you have cloned the repository but have not initialized the submodules
git submodule update --init --recursive
```
# How to Run/Develop
Prepare [Visual Studio Code](https://code.visualstudio.com/) with the extension [Dev Containers](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers)

Additionally, you might need to set up a Docker container environment.

Then, run this project in Dev Container.

You can test the demo in the `am-kernels/kernels/*` folder. (e.g. `am-kernels/kernels/typing-game`).

Run it with:
```
make ARCH=riscv32e-npc run
```

* If you choose `riscv32e-npc`, you need to enter the `npc` directory first and run `make build` to generate the required dependencies.

* If you choose `riscv32-nemu`, you need to enter the `nemu` directory first and run `make menuconfig` to initialize the configuration.

If you need to enable the GUI and audio, you can run the `display` command.
# How to proxy WebRTC traffic
Add this section to `.devcontainer/mediamtx.yml`
```
webrtcICEServers2:
  - url: turn:yout_hostname:your_port
    username: xxx
    password: xxx
```
# Appendix
* [lecture note](https://ysyx.oscc.cc/docs/)
* [mediamtx.yml](https://github.com/bluenviron/mediamtx/blob/main/mediamtx.yml)
