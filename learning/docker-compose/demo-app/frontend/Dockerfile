FROM nginx:latest

COPY ./index.html /usr/share/nginx/html/index.html

#COPY public /usr/share/nginx/html/public

EXPOSE 80

# Use the default Nginx entrypoint
CMD ["nginx", "-g", "daemon off;"]
