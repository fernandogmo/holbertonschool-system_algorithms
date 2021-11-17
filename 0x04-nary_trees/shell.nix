with import <nixpkgs> { };
stdenv.mkDerivation {
  name = "valgrind";
  buildInputs = [
	valgrind
  ];
}
