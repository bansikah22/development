package handlers

import "net/http"

func SetupStaticFileServer(dir string) http.Handler {
	return http.FileServer(http.Dir(dir))
}