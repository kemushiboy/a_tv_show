require 'net/http'
require 'json'
require 'fileutils'

fileName = ARGV[0]
uri = URI('https://api.projectoxford.ai/face/v0/detections')

f = File.binread("/Users/student/Dropbox/faceAPI/pictures/" + ARGV[0] + ".jpg")

uri.query = URI.encode_www_form({
                                # Specify your subscription key
                                'subscription-key' => '6abe860aaca14232bd97736263409893',
                                # Specify values for optional parameters, as needed
                                'analyzesFaceLandmarks' => 'false',
                                'analyzesAge' => 'true',
                                'analyzesGender' => 'true',
                                'analyzesHeadPose' => 'false',
                                })

request = Net::HTTP::Post.new(uri.request_uri)

# Basic Authorization Sample
# request.basic_auth 'username', 'password'
request['Content-type'] = 'application/octet-stream'
img = f
request.body = img

response = Net::HTTP.start(uri.host, uri.port, :use_ssl => uri.scheme == 'https') do |http|
    http.request(request)
end

puts response.body
#File.write('/Users/faceAPI/Ishikawa/' +ARGV[0] + '.txt',response.body)
json_data = JSON.parse(response.body)
File.open('/Users/student/Dropbox/faceAPI/faceId_list.csv','a') do |file|
    json_data.each do |list|
       file.puts list["faceId"] + "," + ARGV[0] + ".jpg"
    end
end