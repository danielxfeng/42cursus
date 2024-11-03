rm -rf ../ex02
mkdir ../ex02
cd ../ex02
touch '01~'
touch '#02#'
echo "find . \( -name '*~' -o -name '#*#' \) -exec rm -v {} +" >> clean