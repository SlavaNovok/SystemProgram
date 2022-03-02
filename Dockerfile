FROM amazonlinux
COPY 1.sh .
RUN chmod +x /1.sh
CMD . /1.sh
