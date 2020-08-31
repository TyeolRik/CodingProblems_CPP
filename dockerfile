# DockerFile for CodingProblems_CPP
# Debian Buster 10.5
FROM gcc:9.3.0

RUN apt install git && git clone "https://github.com/TyeolRik/CodingProblems_CPP.git"

ENTRYPOINT [ "cd", "/root/CodingProblems_CPP" ]