require 'json'
require 'fileutils'
require 'net/http'
require 'csv'

#inputId = ARGV[0]
inputId = "d517e160-9810-4929-ad05-a3519a80a650"
inputIds = []

csv = CSV.open("faceId_list.csv","r")
csv.each_with_index{|line|
inputIds.push(line[0])
}

uri = URI('https://api.projectoxford.ai/face/v0/findsimilars')

uri.query = URI.encode_www_form({
                                # Specify your subscription key
                                'subscription-key' => '6abe860aaca14232bd97736263409893',
                                })
hash = {
    :faceId => inputId,
    :faceIds => inputIds
}

request = Net::HTTP::Post.new(uri.request_uri)

# Basic Authorization Sample
# request.basic_auth 'username', 'password'
request['Content-type'] = 'application/json'

request.body = hash.to_json

response = Net::HTTP.start(uri.host, uri.port, :use_ssl => uri.scheme == 'https') do |http|
    http.request(request)
end

File.write(inputId + "_similar.json", response.body)    
puts response.body