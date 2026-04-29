echo "Usage: source env.sh"

# must be absolute path
ROOT_PATH=/workspaces/codespaces-blank

if [ ! -d "$ROOT_PATH" ]; then
  echo "Error: ROOT_PATH $ROOT_PATH does not exist. Please set it to a valid directory."
  return 1
fi

echo "Setting up environment variables for the project..."

YXYX_HOME=$(realpath $ROOT_PATH/ysyx-workbench)

export AM_HOME=$YXYX_HOME/abstract-machine
export NEMU_HOME=$YXYX_HOME/nemu
export NPC_HOME=$YXYX_HOME/npc
export SOC_HOME=$YXYX_HOME/ysyxSoC
export NVBOARD_HOME=$YXYX_HOME/nvboard
