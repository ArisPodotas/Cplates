cplate() {
    function liner() {
        echo "Usage: cplate [OPTIONS]"
        echo "Options:"
        echo "  -h, --help     Display this help message"
        echo "  --version      Show the script version"
        # echo "  script [DIR]   Generate an script style project inside DIR (will make dir if it does not exist)"
        # echo "  notebook [DIR] Generate a notebook style project inside DIR (will make dir if it does not exist)"
    }
    # Check if no arguments are provided
    if [ "$#" -eq 0 ]; then
        liner
        return 1
    fi
    while [[ "$1" != "" ]]; do
        case $1 in
            -h )
                liner
                return 0
                ;;
            --help )
                liner
                return 0
                ;;
            --version )
                echo "Script Version 1.0"
                return 0
                ;;
            * )
                mkdir -p "$1"
                cp -r "$HOME/Templates/Cplates/content/"* "$1"
                return 0
        esac
        shift
    done
}

alias cplates=cplate
