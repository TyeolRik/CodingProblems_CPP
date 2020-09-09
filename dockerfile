# DockerFile for CodingProblems_CPP
# Debian Buster 10.5
FROM gcc:9.3.0

RUN mkdir "/root/CodingProblems_CPP"

RUN apt update &&\
    apt upgrade -y &&\
    apt install python3-pip -y &&\
    pip3 install requests beautifulsoup4

# RUN apt install git && git clone "https://github.com/TyeolRik/CodingProblems_CPP.git"
