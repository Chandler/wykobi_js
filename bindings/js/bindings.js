// "x1,y2,x2,y2," -> [[x1,y1], [x2,y2]]
function parse_line_segment_string(line_segment_string) {
    split_string = line_segment_string.split(",")
    split_string.pop()

    points = split_string.map(parseFloat)

    line_segment = []
    for(i=0; i < points.length; i+=2) {
      line_segment.push([points[i], points[i+1]])
    }
    return line_segment
}

function buildWykobiApi(WykobiCppModule) {

  segmentTriangleIntersect =
    WykobiCppModule.cwrap(
      'segmentTriangleIntersect',
      'string',
      ['number', 'number', 'number' ,'number',
        'number', 'number', 'number' ,'number',
          'number', 'number'])


  var api = {
    segmentTriangleIntersect: function(...args) {
      return parse_line_segment_string(segmentTriangleIntersect(...args))
    }
  }

  return api
}