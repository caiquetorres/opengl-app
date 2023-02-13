function help() {
  cat <<'EOF'
  Runs the application

  Usage:
      ./run.sh [options]

  Options:
      -h --help                       Display this message
      -p --preset PRESET_NAME  Name of the preset
EOF
}

while test $# -gt 0; do
  case $1 in
  -p | --preset)
    preset=$2
    ;;
  -h | --help)
    help
    exit 0
    ;;
  esac
  shift
done

# TODO: Validate the existing presets

cmake --preset=${preset} -B "build/${preset}"
make -C "build/${preset}"
./build/${preset}/opengl
