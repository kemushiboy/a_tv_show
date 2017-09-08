require 'net/http'
require 'json'
require 'fileutils'
require 'osc-ruby'
require 'csv'

fileName = ARGV[0]
uri = URI('https://api.projectoxford.ai/face/v0/detections')
client = OSC::Client.new('localhost',3333)

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
#File.write('/Users/Ishikawa/faceAPI/' +ARGV[0] + '.json',response.body)
parse = JSON.parse(response.body)
age = parse[0]["attributes"]["age"]
gender = parse[0]["attributes"]["gender"]
faceId = parse[0]["faceId"]

##########
#json_data = JSON.parse(response.body)
#File.open('faceId_list.txt','a') do |file|
#json_data.each do |list|
#file.puts list["faceId"]
#end
#end
##########

inputIds = []

csv = CSV.open("/Users/student/Dropbox/faceAPI/faceId_list.csv","r")
csv.each_with_index{|line|
    inputIds.push(line[0])
}

uri2 = URI('https://api.projectoxford.ai/face/v0/findsimilars')

uri2.query = URI.encode_www_form({
                                # Specify your subscription key
                                'subscription-key' => '6abe860aaca14232bd97736263409893',
                                })
hash = {
    :faceId => faceId,
    :faceIds => inputIds
}

request2 = Net::HTTP::Post.new(uri2.request_uri)

# Basic Authorization Sample
# request.basic_auth 'username', 'password'
request2['Content-type'] = 'application/json'

request2.body = hash.to_json

response2 = Net::HTTP.start(uri.host, uri.port, :use_ssl => uri.scheme == 'https') do |http|
    http.request(request2)
end

#File.write(faceId + "_similar.json", response.body)

similarPictureName = ARGV[0] + ".jpg"
puts response2.body
parse2 = JSON.parse(response2.body)

escapeHash = {"faceId"=>"------"}
parse2.push(escapeHash)

    similarId = parse2[0]["faceId"];
    CSV.foreach("/Users/student/Dropbox/faceAPI/faceId_list.csv") do|row|
        if row.include?(similarId) then
            similarPictureName = row[1]
            puts similarPictureName
        end
    end

Message = OSC::Message.new('/faceAPI',gender,age,similarPictureName)
client.send(Message)




